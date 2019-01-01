/**
 * \file svgLoader.cpp
 * \brief Add Comment Here
 *
 * \ingroup cppcorefiles
 * \date Dec 1, 2018
 * \author sergey skaredov
 */

#include <fstream>

#include "core/utils/utils.h"
#include "core/tinyxml/tinyxml2.h"
#include "core/fileformats/svgLoader.h"

namespace corecvs {

using namespace std;
using namespace tinyxml2;

escape_map SvgLoader::escape_m =
{
    { ',', ' '},
    {'\f', ' '},
    {'\n', ' '},
    {'\r', ' '},
    {'\t', ' '},
    {'\v', ' '},
    {'\0', ' '}
};

color_map SvgShape::color_m =
{
    { "black", RGBColor::Black() },
    { "white", RGBColor::White() },
    {  "gray", RGBColor::Gray()  },
    {   "red", RGBColor::Red()   },
    { "green", RGBColor::Green() },
    {  "blue", RGBColor::Blue()  },
    {  "navy", RGBColor::Navy()  },
    {"purple", RGBColor::Purple()},
    {"yellow", RGBColor::Yellow()},
    {"orange", RGBColor::Orange()}
};

SvgLoader::SvgLoader()
{
    shape_m.emplace("rect", &SvgLoader::getRect);
    shape_m.emplace("circle", &SvgLoader::getCircle);
    shape_m.emplace("ellipse", &SvgLoader::getEllipse);
    shape_m.emplace("line", &SvgLoader::getLine);
    shape_m.emplace("polyline", &SvgLoader::getPolyLine);
    shape_m.emplace("polygon", &SvgLoader::getPolygon);
    shape_m.emplace("path", &SvgLoader::getPath);

    shape_m.emplace("g", &SvgLoader::getGroup);

}

SvgLoader::~SvgLoader()
{}

int SvgLoader::loadSvg(istream &input, SvgFile &svg)
{
    input.seekg(0, input.end);
    int len = input.tellg();
    input.seekg(0, input.beg);

    char data[len];
    input.read(data, len);

    XMLDocument xml;
    int errorID = xml.Parse(data, len);

    if (errorID)
    {
        cout << "SvgLoader::loadSvg: fail loading data" << endl;
        return errorID;
    }

    parseXML(xml, svg);    
    return 0;
}

int SvgLoader::parseXML(XMLDocument &xml, SvgFile &svg)
{
    XMLElement *root = xml.FirstChildElement("svg");
    if (!root)
    {
        cout << "SvgLoader::parseXML: couldn't find root 'svg'\n" << endl;
        return 1;
    }

    svg.width = root->DoubleAttribute("width");
    svg.height = root->DoubleAttribute("height");

    const char *_viewBox = root->Attribute("viewBox");
    
    if (_viewBox) {
        vector<Vector2dd> viewBox = parsePoints(string(_viewBox));

        if (viewBox.size() == 2)
        {
            svg.viewBox = viewBox;
        }
    }
    
    XMLElement *current = root->FirstChildElement();
    while(current)
    {
        const char *name = current->Name();
        if (trace) {
            cout << "Processing <" << name << ">" << endl;
        }

        auto iter = shape_m.find(name);
        if (iter != shape_m.end())
        {
            f_type getShape = iter->second;
            SvgShape *shape = (this->*getShape)(current);
            svg.shapes.push_back(shape);
        }
        
        current = current->NextSiblingElement();
    }
    return 0;
}

vector<Vector2dd> SvgLoader::parsePoints(string data)
{
    locale myLocale("C");
    data = HelperUtils::escapeString(data, escape_m, "");
    vector<string> coords = HelperUtils::stringSplit(data, ' ');
    vector<Vector2dd> points;
    for(int i = 0; i < coords.size(); i += 2) {
        istringstream xs(coords[i]);
        istringstream ys(coords[i+1]);
        xs.imbue(myLocale);
        ys.imbue(myLocale);
        double x, y;
        xs >> x;
        ys >> y;
        points.push_back(Vector2dd(x, y));
    }
    return points;
}

void SvgLoader::initShape(XMLElement *element, SvgShape *shape)
{
    shape->id = element->Attribute("id");
    shape->stroke = element->Attribute("stroke");
    shape->fill = element->Attribute("fill");
    shape->stroke_width = element->IntAttribute("stroke-width");
}

SvgShape* SvgLoader::getRect(XMLElement *element)
{
    SvgRect *rect = new SvgRect();
    initShape(element, rect);
    rect->x = element->DoubleAttribute("x");
    rect->y = element->DoubleAttribute("y");
    rect->w = element->DoubleAttribute("width");
    rect->h = element->DoubleAttribute("height");
    
    if (trace)
    {
        cout << "getRect: x=" << rect->x << ", ";
        cout << "y=" << rect->y << ", ";
        cout << "w=" << rect->w << ", ";
        cout << "h=" << rect->h << endl;
    }
    return rect;
}

SvgShape* SvgLoader::getCircle(XMLElement *element)
{
    SvgCircle *circle = new SvgCircle();
    initShape(element, circle);
    circle->cx = element->DoubleAttribute("cx");
    circle->cy = element->DoubleAttribute("cy");
    circle->r = element->DoubleAttribute("r");
    
    if (trace)
    {
        cout << "getCircle: cx=" << circle->cx << ", ";
        cout << "cy=" << circle->cy << ", ";
        cout << "r=" << circle->r << endl;
    }
    return circle;
}

SvgShape* SvgLoader::getEllipse(XMLElement *element)
{
    SvgEllipse *ellipse = new SvgEllipse();
    initShape(element, ellipse);
    ellipse->cx = element->DoubleAttribute("cx");
    ellipse->cy = element->DoubleAttribute("cy");
    ellipse->rx = element->DoubleAttribute("rx");
    ellipse->ry = element->DoubleAttribute("ry");
    
    if (trace)
    {
        cout << "getEllipse: cx=" << ellipse->cx << ", ";
        cout << "cy=" << ellipse->cy << ", ";
        cout << "rx=" << ellipse->rx << ", ";
        cout << "ry=" << ellipse->ry << endl;
    }
    return ellipse;
}

SvgShape* SvgLoader::getLine(XMLElement *element)
{
    SvgLine *line = new SvgLine();
    initShape(element, line);
    line->x1 = element->DoubleAttribute("x1");
    line->y1 = element->DoubleAttribute("y1");
    line->x2 = element->DoubleAttribute("x2");
    line->y2 = element->DoubleAttribute("y2");
        
    if (trace)
    {
        cout << "getLine: x1=" << line->x1 << ", ";
        cout << "y1=" << line->y1 << ", ";
        cout << "x2=" << line->x2 << ", ";
        cout << "y2=" << line->y2 << endl;
    }
    return line;
}

SvgShape* SvgLoader::getPolyLine(XMLElement *element)
{
    SvgPolyLine *polyline = new SvgPolyLine();
    initShape(element, polyline);

    string attr(element->Attribute("points"));
    vector<Vector2dd> points = parsePoints(attr);
    polyline->points.insert(polyline->points.end(), points.begin(), points.end());

    if (trace)
    {
        cout << "getPolyLine: points=";
        for (Vector2dd v: points)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return polyline;
}

SvgShape* SvgLoader::getPolygon(XMLElement *element)
{
    SvgPolygon *polygon = new SvgPolygon();
    initShape(element, polygon);
    
    string attr(element->Attribute("points"));
    vector<Vector2dd> points = parsePoints(attr);
    polygon->polygon.insert(polygon->polygon.end(), points.begin(), points.end());

    if (trace)
    {
        cout << "getPolygon: points=";
        for (Vector2dd v: points)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return polygon;
}

SvgShape* SvgLoader::getPath(XMLElement *element)
{
    SvgPath *path = new SvgPath;
    initShape(element, path);
    
    string d(element->Attribute("d"));
    d = HelperUtils::escapeString(d, escape_m, "");
    
    locale myLocale("C");
    int index = 0;
    while (index < d.size())
    {
        Command cmd;
        char c = d[index];
        switch(c)
        {
            case 'M': case 'm':
            case 'L': case 'l':
            case 'C': case 'c':
            case 'S': case 's':
            case 'Q': case 'q':
            case 'T': case 't':
            case 'H': case 'h':
            case 'V': case 'v':
            case 'A': case 'a':
            {
                cmd.command = c;
                index++;
                int new_cmd_pos = d.find_first_not_of("-0123456789. ", index);
                string params = d.substr(index, new_cmd_pos - index);
                for (string p: HelperUtils::stringSplit(params, ' '))
                {
                    if (p.size())
                    {
                        istringstream s(p);
                        s.imbue(myLocale);
                        double x;
                        s >> x;
                        cmd.params.push_back(x);
                    }
                }
                index = new_cmd_pos;
                path->commands.push_back(cmd);
                break;
            }
            case 'Z': case 'z':
            {
                cmd.command = c;
                index++;
                path->commands.push_back(cmd);
                break;
            }
            default:
                index++;
                break;
        }
    }

    if (trace)
    {
        cout << "getPath: d=";
        for (Command cmd: path->commands)
        {
            cout << " " << cmd.command;
            for (double p: cmd.params)
            {
                cout << " " << p;
            }
        }
        cout << endl;
    }

    return path;
}

SvgShape *SvgLoader::getGroup(XMLElement *element)
{
    SYNC_PRINT(("SvgLoader::getGroup(): called\n"));
    SvgGroup *group = new SvgGroup;
    initShape(element, group);

    XMLElement *current = element->FirstChildElement();

    while(current)
    {
        const char *name = current->Name();
        if (trace) {
            cout << "Processing <" << name << ">" << endl;
        }

        auto iter = shape_m.find(name);
        if (iter != shape_m.end())
        {
            f_type getShape = iter->second;
            SvgShape *shape = (this->*getShape)(current);
            group->shapes.push_back(shape);
        }

        current = current->NextSiblingElement();
    }
    return group;
}

RGB24Buffer* SvgFile::draw()
{
    RGB24Buffer *buffer = new RGB24Buffer(fround(height), fround(width), RGBColor::White());
    for (SvgShape *shape: shapes)
    {
            shape->draw(buffer);
    }
    return buffer;
}

string  SVGToRGB24BufferLoader::extension(".svg");

bool SVGToRGB24BufferLoader::acceptsFile(const std::string &name)
{
    std::string lowercase = name;
    std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);

    return HelperUtils::endsWith(lowercase, extension);
}

RGB24Buffer *SVGToRGB24BufferLoader::load(const string &name)
{
    SvgFile svg;
    SvgLoader loader;
    std::ifstream stream(name);
    if (!stream) {
        SYNC_PRINT(("can't open file\n"));
        return NULL;
    }

    loader.loadSvg(stream, svg);

   if (svg.shapes.size() == 8) {
       SYNC_PRINT(("Parsing problem\n"));
       return NULL;
   }

   return svg.draw();
}

void SvgGroup::draw(RGB24Buffer *buffer)
{
    for (SvgShape *shape: shapes)
    {
         shape->draw(buffer);
    }
}

void SvgPath::draw(RGB24Buffer *buffer)
{
    if (commands.size() == 0)
    {
        return;
    }

    cursor = {0, 0};
    start_point = {0, 0};
    dest = {0, 0};
    RGBColor color = getColor();
    Curve curve;
    WuRasterizer rast = WuRasterizer();
    BezierRasterizer<RGB24Buffer, WuRasterizer> bezier(*buffer, rast, color);
    for (size_t i = 0; i < commands.size(); i++)
    {
        const Command &command = commands[i];

        last_p = Vector2dd(0.0);
        switch(command.command)
        {
        case 'm':
            last_p = cursor;
        case 'M':
            cursor = command.getVector() + last_p;
            start_point = cursor;
            if (commands[i].params.size() > 2)
            {
                for (int j = 2; j < command.params.size(); j += 2)
                {
                    dest = command.getVector(j);
                    if (command.command == 'm')
                    {
                        dest += cursor;
                    }
                    buffer->drawLine(cursor, dest, color);
                    cursor = dest;
                }
            }
            break;
            /*=================================*/
        case 'l':
            last_p = cursor;
        case 'L':
            dest = command.getVector() + last_p;
            buffer->drawLine(cursor, dest, color);
            cursor = dest;
            break;
            /*=================================*/
        case 'h':
            last_p.x() = cursor.x();
        case 'H':
            buffer->drawHLine(fround(cursor[0]), fround(cursor[1]), fround(command.params[0] + last_p[0]), color);
            cursor[0] = command.params[0] + last_p[0];
            break;
            /*=================================*/
        case 'v':
            last_p[1] = cursor[1];
        case 'V':
            buffer->drawVLine(fround(cursor[0]), fround(cursor[1]), fround(command.params[0] + last_p[1]), color);
            cursor[1] = command.params[0] + last_p[1];
            break;
            /*=================================*/
        case 'Z': case 'z':
            buffer->drawLine(cursor, start_point, color);
            cursor = start_point;
            break;
            /*=================================*/
        case 'c':
            last_p = cursor;
        case 'C':
            control_b = command.getVector(0) + last_p;
            control_c = command.getVector(2) + last_p;
            dest      = command.getVector(4) + last_p;
            curve =
            {
                cursor,
                control_b,
                control_c,
                dest
            };
            bezier.cubicBezierCasteljauApproximationByFlatness(curve);
            cursor = dest;
            break;
            /*=================================*/
        case 's':
            last_p = cursor;
        case 'S':
            dest = command.getVector(2) + last_p;
            if (i > 0)
            {
                char prevAction = commands[i-1].command;
                if ((prevAction != 'C' && prevAction != 'c') &&
                    (prevAction != 'S' && prevAction != 's'))
                {
                    control_b = command.getVector(0) + last_p;
                }
                else
                {
                    control_b = 2 * cursor - control_c;
                }
            }
            control_c = command.getVector() + last_p;
            curve =
            {
                cursor,
                control_b,
                control_c,
                dest
            };

            bezier.cubicBezierCasteljauApproximationByFlatness(curve);
            cursor = dest;
            break;
        case 'q':
        case 'Q':
        case 't':
        case 'T':
            break;
        case 'a':
        case 'A':
            break;
        }
    }
}



}
