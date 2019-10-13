/**
 * \file rateParameters.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 * Generated from physics.xml
 */

#include <vector>
#include <stddef.h>
#include "rateParameters.h"

/**
 *  Looks extremely unsafe because it depends on the order of static initialization.
 *  Should check standard if this is ok
 *
 *  Also it's not clear why removing "= Reflection()" breaks the code;
 **/

namespace corecvs {
#if 0
template<>
Reflection BaseReflection<RateParameters>::reflection = Reflection();
template<>
int BaseReflection<RateParameters>::dummy = RateParameters::staticInit();
#endif
} // namespace corecvs 

SUPPRESS_OFFSET_WARNING_BEGIN


using namespace corecvs;

int RateParameters::staticInit(corecvs::Reflection *toFill)
{
    if (toFill == NULL || toFill->objectSize != 0) {
        SYNC_PRINT(("staticInit(): Contract Violation in <RateParameters>\n"));
         return -1;
    }

    toFill->name = ReflectionNaming(
        "Rate Parameters",
        "Rate Parameters",
        ""
    );

     toFill->objectSize = sizeof(RateParameters);
     

    DoubleField* field0 = new DoubleField
        (
          RateParameters::RC_RATE_ID,
          offsetof(RateParameters, mRcRate),
          0.5,
          "rc rate",
          "rc rate",
          "rc rate",
          true,
         0,
         100,
         1
        );
    field0->widgetHint=BaseField::SPIN_BOX;
    field0->precision=2;
    toFill->fields.push_back(field0);
    /*  */ 
    DoubleField* field1 = new DoubleField
        (
          RateParameters::SUPER_RATE_ID,
          offsetof(RateParameters, mSuperRate),
          0.7,
          "super rate",
          "super rate",
          "super rate",
          true,
         0,
         100,
         1
        );
    field1->widgetHint=BaseField::SPIN_BOX;
    field1->precision=2;
    toFill->fields.push_back(field1);
    /*  */ 
    DoubleField* field2 = new DoubleField
        (
          RateParameters::RC_EXPO_ID,
          offsetof(RateParameters, mRcExpo),
          0.33,
          "rc expo",
          "rc expo",
          "rc expo",
          true,
         0,
         100,
         1
        );
    field2->widgetHint=BaseField::SPIN_BOX;
    field2->precision=2;
    toFill->fields.push_back(field2);
    /*  */ 
    ReflectionDirectory &directory = *ReflectionDirectoryHolder::getReflectionDirectory();
    directory[std::string("Rate Parameters")]= toFill;
   return 0;
}
int RateParameters::relinkCompositeFields()
{
   return 0;
}

SUPPRESS_OFFSET_WARNING_END

