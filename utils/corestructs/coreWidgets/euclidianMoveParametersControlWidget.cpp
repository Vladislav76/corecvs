/**
 * \file euclidianMoveParametersControlWidget.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "euclidianMoveParametersControlWidget.h"
#include "ui_euclidianMoveParametersControlWidget.h"
#include <memory>
#include "qSettingsGetter.h"
#include "qSettingsSetter.h"


EuclidianMoveParametersControlWidget::EuclidianMoveParametersControlWidget(QWidget *parent, bool _autoInit, QString _rootPath)
    : ParametersControlWidgetBase(parent)
    , mUi(new Ui::EuclidianMoveParametersControlWidget)
    , autoInit(_autoInit)
    , rootPath(_rootPath)
{
    mUi->setupUi(this);

    QObject::connect(mUi->xSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->ySpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->zSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->alphaSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->betaSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->gammaSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
}

EuclidianMoveParametersControlWidget::~EuclidianMoveParametersControlWidget()
{

    delete mUi;
}

void EuclidianMoveParametersControlWidget::loadParamWidget(WidgetLoader &loader)
{
    std::unique_ptr<EuclidianMoveParameters> params(createParameters());
    loader.loadParameters(*params, rootPath);
    setParameters(*params);
}

void EuclidianMoveParametersControlWidget::saveParamWidget(WidgetSaver  &saver)
{
    saver.saveParameters(*std::unique_ptr<EuclidianMoveParameters>(createParameters()), rootPath);
}

void EuclidianMoveParametersControlWidget::getParameters(EuclidianMoveParameters& params) const
{
    params = *std::unique_ptr<EuclidianMoveParameters>(createParameters());
}


EuclidianMoveParameters *EuclidianMoveParametersControlWidget::createParameters() const
{

    /**
     * We should think of returning parameters by value or saving them in a preallocated place
     **/


    return new EuclidianMoveParameters(
          mUi->xSpinBox->value()
        , mUi->ySpinBox->value()
        , mUi->zSpinBox->value()
        , mUi->alphaSpinBox->value()
        , mUi->betaSpinBox->value()
        , mUi->gammaSpinBox->value()
    );
}

void EuclidianMoveParametersControlWidget::setParameters(const EuclidianMoveParameters &input)
{
    // Block signals to send them all at once
    bool wasBlocked = blockSignals(true);
    mUi->xSpinBox->setValue(input.x());
    mUi->ySpinBox->setValue(input.y());
    mUi->zSpinBox->setValue(input.z());
    mUi->alphaSpinBox->setValue(input.alpha());
    mUi->betaSpinBox->setValue(input.beta());
    mUi->gammaSpinBox->setValue(input.gamma());
    blockSignals(wasBlocked);
    emit paramsChanged();
}

void EuclidianMoveParametersControlWidget::setParametersVirtual(void *input)
{
    // Modify widget parameters from outside
    EuclidianMoveParameters *inputCasted = static_cast<EuclidianMoveParameters *>(input);
    setParameters(*inputCasted);
}
