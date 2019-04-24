#ifndef MIXER_CHANNEL_OPERATION_PARAMETERS_H_
#define MIXER_CHANNEL_OPERATION_PARAMETERS_H_
/**
 * \file mixerChannelOperationParameters.h
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 * Generated from physics.xml
 */

#include "core/reflection/reflection.h"
#include "core/reflection/defaultSetter.h"
#include "core/reflection/printerVisitor.h"

/*
 *  Embed includes.
 */
/*
 *  Additional includes for Composite Types.
 */

// using namespace corecvs;

/*
 *  Additional includes for Pointer Types.
 */

// namespace corecvs {
// }
/*
 *  Additional includes for enum section.
 */

/**
 * \brief Mixer Channel Operation Parameters 
 * Mixer Channel Operation Parameters 
 **/
class MixerChannelOperationParameters : public corecvs::BaseReflection<MixerChannelOperationParameters>
{
public:
    enum FieldId {
        MIN_ID,
        MAX_ID,
        MIXER_CHANNEL_OPERATION_PARAMETERS_FIELD_ID_NUM
    };

    /** Section with variables */

    /** 
     * \brief min 
     * min 
     */
    double mMin;

    /** 
     * \brief max 
     * max 
     */
    double mMax;

    /** Static fields init function, this is used for "dynamic" field initialization */ 
    static int staticInit(corecvs::Reflection *toFill);

    static int relinkCompositeFields();

    /** Section with getters */
    const void *getPtrById(int fieldId) const
    {
        return (const unsigned char *)(this) + fields()[fieldId]->offset;
    }
    double min() const
    {
        return mMin;
    }

    double max() const
    {
        return mMax;
    }

    /* Section with setters */
    void setMin(double min)
    {
        mMin = min;
    }

    void setMax(double max)
    {
        mMax = max;
    }

    /* Section with embedded classes */
    /* visitor pattern - http://en.wikipedia.org/wiki/Visitor_pattern */
template<class VisitorType>
    void accept(VisitorType &visitor)
    {
        visitor.visit(mMin,                       static_cast<const corecvs::DoubleField *>(fields()[MIN_ID]));
        visitor.visit(mMax,                       static_cast<const corecvs::DoubleField *>(fields()[MAX_ID]));
    }

    MixerChannelOperationParameters()
    {
        corecvs::DefaultSetter setter;
        accept(setter);
    }

    MixerChannelOperationParameters(
          double min
        , double max
    )
    {
        mMin = min;
        mMax = max;
    }

    bool operator ==(const MixerChannelOperationParameters &other) const 
    {
        if ( !(this->mMin == other.mMin)) return false;
        if ( !(this->mMax == other.mMax)) return false;
        return true;
    }
    friend std::ostream& operator << (std::ostream &out, MixerChannelOperationParameters &toSave)
    {
        corecvs::PrinterVisitor printer(out);
        toSave.accept<corecvs::PrinterVisitor>(printer);
        return out;
    }

    void print ()
    {
        std::cout << *this;
    }
};
#endif  //MIXER_CHANNEL_OPERATION_PARAMETERS_H_
