/*
 * Your License or Copyright can go here
 */

#pragma once

#include "SIMPLib/Common/SIMPLibSetGetMacros.h"
#include "SIMPLib/CoreFilters/FileWriter.h"
#include "SIMPLib/DataArrays/StringDataArray.h"
#include "SIMPLib/Filtering/AbstractFilter.h"
#include "SIMPLib/SIMPLib.h"

#include "MASSIFUtilities/MASSIFUtilitiesDLLExport.h"

/**
 * @brief The FFTHDFWriterFilter class. See [Filter documentation](@ref ffthdfwriterfilter) for details.
 */
class MASSIFUtilities_EXPORT FFTHDFWriterFilter : public AbstractFilter
{
  Q_OBJECT /* Need this for Qt's signals and slots mechanism to work */
  PYB11_CREATE_BINDINGS(FFTHDFWriterFilter SUPERCLASS AbstractFilter) PYB11_PROPERTY(QString OutputFile READ getOutputFile WRITE setOutputFile)
      PYB11_PROPERTY(DataArrayPath FeatureIdsArrayPath READ getFeatureIdsArrayPath WRITE setFeatureIdsArrayPath)
          PYB11_PROPERTY(DataArrayPath CellPhasesArrayPath READ getCellPhasesArrayPath WRITE setCellPhasesArrayPath)
              PYB11_PROPERTY(DataArrayPath CellEulerAnglesArrayPath READ getCellEulerAnglesArrayPath WRITE setCellEulerAnglesArrayPath)

                  public : SIMPL_SHARED_POINTERS(FFTHDFWriterFilter) SIMPL_FILTER_NEW_MACRO(FFTHDFWriterFilter) SIMPL_TYPE_MACRO_SUPER_OVERRIDE(FFTHDFWriterFilter, AbstractFilter)

                               ~FFTHDFWriterFilter() override;

  SIMPL_FILTER_PARAMETER(QString, OutputFile)
  Q_PROPERTY(QString OutputFile READ getOutputFile WRITE setOutputFile)

  SIMPL_INSTANCE_PROPERTY(bool, WritePipeline)

  SIMPL_INSTANCE_PROPERTY(bool, AppendToExisting)
  //-------------------------------------------------------------------

  SIMPL_FILTER_PARAMETER(DataArrayPath, FeatureIdsArrayPath)
  Q_PROPERTY(DataArrayPath FeatureIdsArrayPath READ getFeatureIdsArrayPath WRITE setFeatureIdsArrayPath)

  SIMPL_FILTER_PARAMETER(DataArrayPath, CellPhasesArrayPath)
  Q_PROPERTY(DataArrayPath CellPhasesArrayPath READ getCellPhasesArrayPath WRITE setCellPhasesArrayPath)

  SIMPL_FILTER_PARAMETER(DataArrayPath, CellEulerAnglesArrayPath)
  Q_PROPERTY(DataArrayPath CellEulerAnglesArrayPath READ getCellEulerAnglesArrayPath WRITE setCellEulerAnglesArrayPath)

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
   * @brief readFilterParameters Reimplemented from @see AbstractFilter class
   */
  void readFilterParameters(AbstractFilterParametersReader* reader, int index) override;

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
  FFTHDFWriterFilter();

  /**
   * @brief dataCheck Checks for the appropriate parameter values and availability of arrays
   */
  void dataCheck();

  /**
   * @brief openFile Opens or creates an HDF5 file to write data into
   * @param append Should a new file be created or append data to a currently existing file
   * @return
   */
  hid_t openFile(bool append = false);

  /**
   * @brief closeFile Closes the currently open file
   * @return Integer error value
   */
  herr_t closeFile();

  /**
   * @brief writePipeline Writes the existing pipeline to the HDF5 file
   * @return
   */
  int writePipeline();

  /**
   * @brief writeXdmfHeader Writes the Xdmf header
   * @param out QTextStream for output
   */
  void writeXdmfHeader(QTextStream& out);

  /**
   * @brief writeXdmfFooter Writes the Xdmf footer
   * @param out QTextStream for output
   */
  void writeXdmfFooter(QTextStream& out);

private:
  DEFINE_DATAARRAY_VARIABLE(int32_t, FeatureIds)
  DEFINE_DATAARRAY_VARIABLE(int32_t, CellPhases)
  DEFINE_DATAARRAY_VARIABLE(float, CellEulerAngles)

  hid_t m_FileId;

public:
  FFTHDFWriterFilter(const FFTHDFWriterFilter&) = delete;            // Copy Constructor Not Implemented
  FFTHDFWriterFilter(FFTHDFWriterFilter&&) = delete;                 // Move Constructor Not Implemented
  FFTHDFWriterFilter& operator=(const FFTHDFWriterFilter&) = delete; // Copy Assignment Not Implemented
  FFTHDFWriterFilter& operator=(FFTHDFWriterFilter&&) = delete;      // Move Assignment Not Implemented
};

