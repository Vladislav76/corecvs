#include "patternDetectorParametersWidget.h"
#include "ui_patternDetectorParametersWidget.h"
#include "core/patterndetection/patternDetector.h"

#include <reflectionWidget.h>

using namespace corecvs;

PatternDetectorParametersWidget::PatternDetectorParametersWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatternDetectorParametersWidget)
{
    ui->setupUi(this);

    std::vector<std::string> hints;
    hints = PatternDetectorFabric::getInstance()->getCaps();

    for (size_t id = 0; id < hints.size(); id++)
    {
        std::string hint = hints[id];
        QString str = QString::fromStdString(hint);
        ui->providerComboBox->addItem(str);

        PatternDetector *detector = PatternDetectorFabric::getInstance()->fabricate(hint);

        ProviderParametersWidgetMetadata *metadata = new ProviderParametersWidgetMetadata;
        providerMetadata.push_back(metadata);

        metadata->id = id;
        metadata->providerName = hint;
        metadata->tabWidget = new QWidget;
        QGridLayout *layout = new QGridLayout();
        metadata->tabWidget->setLayout(layout);

        std::map<std::string, corecvs::DynamicObject> defaultParameters = detector->getParameters();

        if (defaultParameters.empty()) {
            SYNC_PRINT(("There are no parameters\n"));
            return;
        } else {
            SYNC_PRINT(("There are %" PRISIZE_T " parameters\n", defaultParameters.size()));
        }

        for (auto &it : defaultParameters)
        {            
            ReflectionWidget *refWidget = new ReflectionWidget(it.second.reflection);
            layout->addWidget(new QLabel(QString::fromStdString(it.first)), layout->rowCount(), 0 );
            layout->addWidget(refWidget,                                    layout->rowCount(), 1);

            metadata->reflectionWidgets[it.first] = refWidget;
            connect(refWidget, SIGNAL(paramsChanged()), metadata, SLOT(uiParamsChanged()));
        }

        ui->tabWidget->addTab(metadata->tabWidget, QString::fromStdString(hint));
        connect(metadata, SIGNAL(paramsChanged(int)), this, SLOT(tabParamsChanged(int)));


        delete_safe(detector);
        //knownParameters.emplace_back(str);
        SYNC_PRINT(("PatternDetectorParametersWidget(): %s provider added\n", str.toStdString().c_str()));
    }
    connect(ui->providerComboBox, SIGNAL(activated(int)), ui->tabWidget, SLOT(setCurrentIndex(int)));
    connect(ui->providerComboBox, SIGNAL(activated(int)), this, SLOT(uiParamsChanged()));

    /**/
}

PatternDetectorParametersWidget::~PatternDetectorParametersWidget()
{
    delete ui;
    for (ProviderParametersWidgetMetadata *data : providerMetadata)
    {
        delete_safe(data);
    }

}

GeneralPatternDetectorParameters PatternDetectorParametersWidget::getParameters()
{
    GeneralPatternDetectorParameters toReturn;
    size_t id = (size_t)ui->providerComboBox->currentIndex();
    toReturn.provider = providerMetadata[id]->providerName;


    for (auto &it : providerMetadata[id]->reflectionWidgets)
    {
        std::string name = it.first;
        ReflectionWidget *widget = it.second;

        toReturn.providerParameters.emplace(name, DynamicObject(widget->reflection));
        widget->getParameters(toReturn.providerParameters[name].rawObject);
    }

    return toReturn;
}

void PatternDetectorParametersWidget::setCurrentToDefaults()
{

}

void PatternDetectorParametersWidget::tabParamsChanged(int tabIndex)
{
     SYNC_PRINT(("PatternDetectorParametersWidget::tabParamsChanged(%d): called\n", tabIndex));
     int id = ui->providerComboBox->currentIndex();

     if (id == tabIndex) {
        emit paramsChanged();
     }
}

void PatternDetectorParametersWidget::uiParamsChanged()
{
     SYNC_PRINT(("PatternDetectorParametersWidget::uiParamsChanged(): called\n"));
     emit paramsChanged();
}

void ProviderParametersWidgetMetadata::uiParamsChanged()
{
    SYNC_PRINT(("ProviderParametersWidgetMetadata::uiParamsChanged(): called for %d\n", id));
    emit paramsChanged(id);
}

ProviderParametersWidgetMetadata::~ProviderParametersWidgetMetadata()
{

}
