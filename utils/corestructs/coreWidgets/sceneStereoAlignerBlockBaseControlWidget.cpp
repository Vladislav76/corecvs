/**
 * \file sceneStereoAlignerBlockBaseControlWidget.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "sceneStereoAlignerBlockBaseControlWidget.h"
#include "ui_sceneStereoAlignerBlockBaseControlWidget.h"
#include <memory>
#include "qSettingsGetter.h"
#include "qSettingsSetter.h"

#include "stereoAlignParametersControlWidget.h"

SceneStereoAlignerBlockBaseControlWidget::SceneStereoAlignerBlockBaseControlWidget(QWidget *parent, bool _autoInit, QString _rootPath)
    : ParametersControlWidgetBase(parent)
    , mUi(new Ui::SceneStereoAlignerBlockBaseControlWidget)
    , autoInit(_autoInit)
    , rootPath(_rootPath)
{
    mUi->setupUi(this);

    QObject::connect(mUi->inFixture1SpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->inCamera1SpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->inFixture2SpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->inCamera2SpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->parametersControlWidget, SIGNAL(paramsChanged()), this, SIGNAL(paramsChanged()));
}

SceneStereoAlignerBlockBaseControlWidget::~SceneStereoAlignerBlockBaseControlWidget()
{

    delete mUi;
}

void SceneStereoAlignerBlockBaseControlWidget::loadParamWidget(WidgetLoader &loader)
{
    std::unique_ptr<SceneStereoAlignerBlockBase> params(createParameters());
    loader.loadParameters(*params, rootPath);
    setParameters(*params);
}

void SceneStereoAlignerBlockBaseControlWidget::saveParamWidget(WidgetSaver  &saver)
{
    saver.saveParameters(*std::unique_ptr<SceneStereoAlignerBlockBase>(createParameters()), rootPath);
}

void SceneStereoAlignerBlockBaseControlWidget::getParameters(SceneStereoAlignerBlockBase& params) const
{
    params = *std::unique_ptr<SceneStereoAlignerBlockBase>(createParameters());
}


SceneStereoAlignerBlockBase *SceneStereoAlignerBlockBaseControlWidget::createParameters() const
{

    /**
     * We should think of returning parameters by value or saving them in a preallocated place
     **/


    return new SceneStereoAlignerBlockBase(
          NULL
        , mUi->inFixture1SpinBox->value()
        , mUi->inCamera1SpinBox->value()
        , mUi->inFixture2SpinBox->value()
        , mUi->inCamera2SpinBox->value()
        , *std::unique_ptr<StereoAlignParameters>(mUi->parametersControlWidget->createParameters())
        , NULL
        , NULL
        , NULL
        , NULL
        , NULL
        , NULL
    );
}

void SceneStereoAlignerBlockBaseControlWidget::setParameters(const SceneStereoAlignerBlockBase &input)
{
    // Block signals to send them all at once
    bool wasBlocked = blockSignals(true);
    mUi->inFixture1SpinBox->setValue(input.inFixture1());
    mUi->inCamera1SpinBox->setValue(input.inCamera1());
    mUi->inFixture2SpinBox->setValue(input.inFixture2());
    mUi->inCamera2SpinBox->setValue(input.inCamera2());
    mUi->parametersControlWidget->setParameters(input.parameters());
    blockSignals(wasBlocked);
    emit paramsChanged();
}

void SceneStereoAlignerBlockBaseControlWidget::setParametersVirtual(void *input)
{
    // Modify widget parameters from outside
    SceneStereoAlignerBlockBase *inputCasted = static_cast<SceneStereoAlignerBlockBase *>(input);
    setParameters(*inputCasted);
}
