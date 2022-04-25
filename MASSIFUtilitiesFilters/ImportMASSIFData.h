/*
 * Your License or Copyright can go here
 */

#pragma once

#include "SIMPLib/Common/SIMPLibSetGetMacros.h"
#include "SIMPLib/Filtering/AbstractFilter.h"
#include "SIMPLib/SIMPLib.h"

#include "MASSIFUtilities/MASSIFUtilitiesDLLExport.h"

/**
 * @brief The ImportMASSIFData class. See [Filter documentation](@ref importmassifdata) for details.
 */
class MASSIFUtilities_EXPORT ImportMASSIFData : public AbstractFilter
{
  Q_OBJECT
  PYB11_CREATE_BINDINGS(ImportMASSIFData SUPERCLASS AbstractFilter)
  PYB11_PROPERTY(QString MassifInputFilePath READ getMassifInputFilePath WRITE setMassifInputFilePath)
  PYB11_PROPERTY(QString FilePrefix READ getFilePrefix WRITE setFilePrefix)
  PYB11_PROPERTY(int StepNumber READ getStepNumber WRITE setStepNumber)

public:
  SIMPL_SHARED_POINTERS(ImportMASSIFData)
  SIMPL_FILTER_NEW_MACRO(ImportMASSIFData)
  SIMPL_TYPE_MACRO_SUPER_OVERRIDE(ImportMASSIFData, AbstractFilter)

  ~ImportMASSIFData() override;

  SIMPL_FILTER_PARAMETER(QString, MassifInputFilePath)
  Q_PROPERTY(QString MassifInputFilePath READ getMassifInputFilePath WRITE setMassifInputFilePath)

  SIMPL_FILTER_PARAMETER(QString, FilePrefix)
  Q_PROPERTY(QString FilePrefix READ getFilePrefix WRITE setFilePrefix)

  SIMPL_FILTER_PARAMETER(int, StepNumber)
  Q_PROPERTY(int StepNumber READ getStepNumber WRITE setStepNumber)

  /**
   * @brief getCompiledLibraryName Reimplemented from @see AbstractFilter class
   */
  const QString getCompiledLibraryName() const override;

  /**
   * @brief getBrandingString Returns the branding string for the filter, which is a tag
   * used to denote the filter's association with specific plugins
   * @return Branding string
   */
  const QString getBrandingString() const override;

  /**
   * @brief getFilterVersion Returns a version string for this filter. Default
   * value is an empty string.
   * @return
   */
  const QString getFilterVersion() const override;

  /**
   * @brief newFilterInstance Reimplemented from @see AbstractFilter class
   */
  AbstractFilter::Pointer newFilterInstance(bool copyFilterParameters) const override;

  /**
   * @brief getGroupName Reimplemented from @see AbstractFilter class
   */
  const QString getGroupName() const override;

  /**
   * @brief getSubGroupName Reimplemented from @see AbstractFilter class
   */
  const QString getSubGroupName() const override;

  /**
   * @brief getUuid Return the unique identifier for this filter.
   * @return A QUuid object.
   */
  const QUuid getUuid() override;

  /**
   * @brief getHumanLabel Reimplemented from @see AbstractFilter class
   */
  const QString getHumanLabel() const override;

  /**
   * @brief setupFilterParameters Reimplemented from @see AbstractFilter class
   */
  void setupFilterParameters() override;

  /**
   * @brief execute Reimplemented from @see AbstractFilter class
   */
  void execute() override;

  /**
   * @brief preflight Reimplemented from @see AbstractFilter class
   */
  void preflight() override;

Q_SIGNALS:
  /**
   * @brief updateFilterParameters Emitted when the Filter requests all the latest Filter parameters
   * be pushed from a user-facing control (such as a widget)
   * @param filter Filter instance pointer
   */
  void updateFilterParameters(AbstractFilter* filter);

  /**
   * @brief parametersChanged Emitted when any Filter parameter is changed internally
   */
  void parametersChanged();

  /**
   * @brief preflightAboutToExecute Emitted just before calling dataCheck()
   */
  void preflightAboutToExecute();

  /**
   * @brief preflightExecuted Emitted just after calling dataCheck()
   */
  void preflightExecuted();

protected:
  ImportMASSIFData();

  /**
   * @brief dataCheck Checks for the appropriate parameter values and availability of arrays
   */
  void dataCheck();

  /**
   * @brief Initializes all the private instance variables.
   */
  void initialize();

private:
  QString m_PaddedStep = "";

  DEFINE_DATAARRAY_WEAKPTR(float, DField)
  DEFINE_DATAARRAY_WEAKPTR(float, EField)
  DEFINE_DATAARRAY_WEAKPTR(float, SField)

  /**
   * @brief createDataArrayPaths
   * @return
   */
  QVector<DataArrayPath> createDataArrayPaths();

  /**
   * @brief createHDF5DatasetPaths
   * @return
   */
  QVector<QString> createHDF5DatasetPaths();

  /**
   * @brief getDataContainerGeometry
   * @param tDims
   * @param origin
   * @param res
   */
  void getDataContainerGeometry(QVector<size_t>& tDims, QVector<float>& origin, QVector<float>& res);

  /**
   * @brief readIDataArray
   * @param gid
   * @param name
   * @param metaDataOnly
   * @return
   */
  IDataArray::Pointer readIDataArray(hid_t gid, const QString& name, QVector<size_t> geoDims, bool metaDataOnly);

public:
  ImportMASSIFData(const ImportMASSIFData&) = delete;            // Copy Constructor Not Implemented
  ImportMASSIFData(ImportMASSIFData&&) = delete;                 // Move Constructor Not Implemented
  ImportMASSIFData& operator=(const ImportMASSIFData&) = delete; // Copy Assignment Not Implemented
  ImportMASSIFData& operator=(ImportMASSIFData&&) = delete;      // Move Assignment Not Implemented
};

