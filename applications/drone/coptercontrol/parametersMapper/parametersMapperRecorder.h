#ifndef PARAMETERS_MAPPER_COPTER_H_
#define PARAMETERS_MAPPER_COPTER_H_
/**
 * \file parametersMapperCopter.h
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include <iostream>
#include <QtCore/QSharedPointer>

#include "core/reflection/reflection.h"
#include "core/reflection/defaultSetter.h"

#include "baseParametersControlWidget.h"
#include "copterControlWidget.h"
#include "presentationParametersControlWidget.h"

class ParametersMapperCopter : public QObject
{
    Q_OBJECT
public:
    ParametersMapperCopter();

    void setBaseParametersControlWidget(BaseParametersControlWidget *widget);
    void setCopterControlWidget(CopterControlWidget *widget);
    void setPresentationParametersControlWidget(PresentationParametersControlWidget *widget);

public slots:
    void paramsChanged();

signals:
    void baseParametersParamsChanged(QSharedPointer<BaseParameters> params);
    void copterParamsChanged(QSharedPointer<Copter> params);
    void presentationParametersParamsChanged(QSharedPointer<PresentationParameters> params);

private:
    BaseParametersControlWidget *mBaseParametersControlWidget;
    CopterControlWidget *mCopterControlWidget;
    PresentationParametersControlWidget *mPresentationParametersControlWidget;
};
#endif //PARAMETERS_MAPPER_COPTER_H_