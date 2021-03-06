/**
 * \file chessBoardCornerDetectorParamsBase.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include <vector>
#include <stddef.h>
#include "chessBoardCornerDetectorParamsBase.h"

/**
 *  Looks extremely unsafe because it depends on the order of static initialization.
 *  Should check standard if this is ok
 *
 *  Also it's not clear why removing "= Reflection()" breaks the code;
 **/

namespace corecvs {
template<>
Reflection BaseReflection<ChessBoardCornerDetectorParamsBase>::reflection = Reflection();
template<>
int BaseReflection<ChessBoardCornerDetectorParamsBase>::dummy = ChessBoardCornerDetectorParamsBase::staticInit();
} // namespace corecvs 

SUPPRESS_OFFSET_WARNING_BEGIN


using namespace corecvs;

int ChessBoardCornerDetectorParamsBase::staticInit()
{

    ReflectionNaming &nameing = naming();
    nameing = ReflectionNaming(
        "Chess Board Corner Detector Params Base",
        "Chess Board Corner Detector Params Base",
        ""
    );

     getReflection()->objectSize = sizeof(ChessBoardCornerDetectorParamsBase);
     

    BoolField* field0 = new BoolField
        (
          ChessBoardCornerDetectorParamsBase::PRODUCEDEBUG_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mProduceDebug),
          false,
          "produceDebug",
          "produceDebug",
          "produceDebug"
        );
    field0->widgetHint=BaseField::CHECK_BOX;
    fields().push_back(field0);
    /*  */ 
    BoolField* field1 = new BoolField
        (
          ChessBoardCornerDetectorParamsBase::FLOATSPEEDUP_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mFloatSpeedup),
          true,
          "floatSpeedup",
          "floatSpeedup",
          "floatSpeedup"
        );
    field1->widgetHint=BaseField::CHECK_BOX;
    fields().push_back(field1);
    /*  */ 
    DoubleField* field2 = new DoubleField
        (
          ChessBoardCornerDetectorParamsBase::NORMALIZEPERCENTILE_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mNormalizePercentile),
          5,
          "normalizePercentile",
          "normalizePercentile",
          "Brightness percentile to be cut",
          true,
         0,
         100,
         1
        );
    field2->widgetHint=BaseField::SPIN_BOX;
    field2->suffixHint="%";
    field2->precision=2;
    fields().push_back(field2);
    /*  */ 
    DoubleField* field3 = new DoubleField
        (
          ChessBoardCornerDetectorParamsBase::SECTORSIZEDEG_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mSectorSizeDeg),
          90,
          "sectorSizeDeg",
          "sectorSizeDeg",
          "Sector size in deg"
        );
    field3->widgetHint=BaseField::SPIN_BOX;
    field3->suffixHint="deg";
    field3->precision=2;
    fields().push_back(field3);
    /*  */ 
    IntField* field4 = new IntField
        (
          ChessBoardCornerDetectorParamsBase::HISTOGRAMBINS_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mHistogramBins),
          50,
          "histogramBins",
          "histogramBins",
          "Number of bins for computing edge direction histogram",
          true,
         0,
         999999,
         1
        );
    fields().push_back(field4);
    /*  */ 
    DoubleField* field5 = new DoubleField
        (
          ChessBoardCornerDetectorParamsBase::MINANGLEDEG_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mMinAngleDeg),
          30,
          "minAngleDeg",
          "minAngleDeg",
          "Minimal angle between edges in deg"
        );
    field5->widgetHint=BaseField::SPIN_BOX;
    field5->suffixHint="deg";
    field5->precision=2;
    fields().push_back(field5);
    /*  */ 
    IntField* field6 = new IntField
        (
          ChessBoardCornerDetectorParamsBase::NEIGHBORHOOD_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mNeighborhood),
          25,
          "neighborhood",
          "neighborhood",
          "Typical radius for estimating edge-related data and refinig corner positions",
          true,
         0,
         999999,
         1
        );
    fields().push_back(field6);
    /*  */ 
    DoubleField* field7 = new DoubleField
        (
          ChessBoardCornerDetectorParamsBase::GRADTHRESHOLD_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mGradThreshold),
          0.1,
          "gradThreshold",
          "gradThreshold",
          "Gradient magnitude threshold"
        );
    field7->widgetHint=BaseField::SPIN_BOX;
    field7->precision=2;
    fields().push_back(field7);
    /*  */ 
    DoubleField* field8 = new DoubleField
        (
          ChessBoardCornerDetectorParamsBase::ORIENTATIONINLIERTHRESHOLD_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mOrientationInlierThreshold),
          0.25,
          "orientationInlierThreshold",
          "orientationInlierThreshold",
          "Gradient orientation inlier threshold"
        );
    field8->widgetHint=BaseField::SPIN_BOX;
    field8->precision=2;
    fields().push_back(field8);
    /*  */ 
    DoubleField* field9 = new DoubleField
        (
          ChessBoardCornerDetectorParamsBase::INLIERDISTANCETHRESHOLD_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mInlierDistanceThreshold),
          5,
          "inlierDistanceThreshold",
          "inlierDistanceThreshold",
          "Threshold for distance to edge"
        );
    field9->widgetHint=BaseField::SPIN_BOX;
    field9->precision=2;
    fields().push_back(field9);
    /*  */ 
    DoubleField* field10 = new DoubleField
        (
          ChessBoardCornerDetectorParamsBase::UPDATETHRESHOLD_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mUpdateThreshold),
          4,
          "updateThreshold",
          "updateThreshold",
          "Threshold for maximal corner-position update"
        );
    field10->widgetHint=BaseField::SPIN_BOX;
    field10->precision=2;
    fields().push_back(field10);
    /*  */ 
    DoubleField* field11 = new DoubleField
        (
          ChessBoardCornerDetectorParamsBase::SCORETHRESHOLD_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mScoreThreshold),
          0,
          "scoreThreshold",
          "scoreThreshold",
          "Threshold for final score"
        );
    field11->widgetHint=BaseField::SPIN_BOX;
    field11->precision=2;
    fields().push_back(field11);
    /*  */ 
    IntField* field12 = new IntField
        (
          ChessBoardCornerDetectorParamsBase::NROUNDS_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mNRounds),
          3,
          "nRounds",
          "nRounds",
          "Number of orientation/position refinement rounds",
          true,
         0,
         999999,
         1
        );
    fields().push_back(field12);
    /*  */ 
    DoubleField* field13 = new DoubleField
        (
          ChessBoardCornerDetectorParamsBase::MEANSHIFTBANDWIDTH_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mMeanshiftBandwidth),
          1,
          "meanshiftBandwidth",
          "meanshiftBandwidth",
          "Meanshift smoothing stdev"
        );
    field13->widgetHint=BaseField::SPIN_BOX;
    field13->precision=2;
    fields().push_back(field13);
    /*  */ 
    IntField* field14 = new IntField
        (
          ChessBoardCornerDetectorParamsBase::NMSLOCALITY_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mNmsLocality),
          20,
          "nmsLocality",
          "nmsLocality",
          "Non Minimal Supresstion locality area",
          true,
         0,
         999999,
         1
        );
    fields().push_back(field14);
    /*  */ 
    DoubleField* field15 = new DoubleField
        (
          ChessBoardCornerDetectorParamsBase::NMSTHRESHOLD_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mNmsThreshold),
          0.025,
          "nmsThreshold",
          "nmsThreshold",
          "Non Minimal Supresstion threshold",
          true,
         0,
         99,
         1
        );
    field15->widgetHint=BaseField::SPIN_BOX;
    field15->precision=3;
    fields().push_back(field15);
    /*  */ 
    double mPatternRadius_dv[] = {4,8,12};
    DoubleVectorField* field16 = new DoubleVectorField
        (
          ChessBoardCornerDetectorParamsBase::PATTERNRADIUS_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mPatternRadius),
          vector<double>(mPatternRadius_dv, mPatternRadius_dv + 3),
          3,
          "patternRadius",
          "patternRadius",
          "Radius for multi-scale pattern detection",
          true,
         0,
         999999,
         1
        );
    field16->precision=2;
    fields().push_back(field16);
    /*  */ 
    double mPatternStartAngleDeg_dv[] = {0,45};
    DoubleVectorField* field17 = new DoubleVectorField
        (
          ChessBoardCornerDetectorParamsBase::PATTERNSTARTANGLEDEG_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mPatternStartAngleDeg),
          vector<double>(mPatternStartAngleDeg_dv, mPatternStartAngleDeg_dv + 2),
          2,
          "patternStartAngleDeg",
          "patternStartAngleDeg",
          "Angle for rotation-variant detection",
          true,
         0,
         999999,
         1
        );
    field17->precision=2;
    fields().push_back(field17);
    /*  */ 
    double mCornerScores_dv[] = {4,8,12};
    DoubleVectorField* field18 = new DoubleVectorField
        (
          ChessBoardCornerDetectorParamsBase::CORNERSCORES_ID,
          offsetof(ChessBoardCornerDetectorParamsBase, mCornerScores),
          vector<double>(mCornerScores_dv, mCornerScores_dv + 3),
          3,
          "cornerScores",
          "cornerScores",
          "Radius for corner-scoring",
          true,
         0,
         999999,
         1
        );
    field18->precision=2;
    fields().push_back(field18);
    /*  */ 
    ReflectionDirectory &directory = *ReflectionDirectoryHolder::getReflectionDirectory();
    directory[std::string("Chess Board Corner Detector Params Base")]= &reflection;
   return 0;
}
int ChessBoardCornerDetectorParamsBase::relinkCompositeFields()
{
   return 0;
}

SUPPRESS_OFFSET_WARNING_END


