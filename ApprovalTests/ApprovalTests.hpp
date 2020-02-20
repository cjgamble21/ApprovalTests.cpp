#ifndef APPROVALTESTS_CPP_APPROVALS_HPP
#define APPROVALTESTS_CPP_APPROVALS_HPP

// Created with:
//   cd ApprovalTests.cpp
//   ./scripts/create_simulated_single_header.sh

#include "ApprovalTests/ApprovalTestsVersion.h"
#include "ApprovalTests/Approvals.h"
#include "ApprovalTests/CombinationApprovals.h"
#include "ApprovalTests/comparators/ComparatorDisposer.h"
#include "ApprovalTests/comparators/ComparatorFactory.h"
#include "ApprovalTests/comparators/TextFileComparator.h"
#include "ApprovalTests/core/ApprovalComparator.h"
#include "ApprovalTests/core/ApprovalException.h"
#include "ApprovalTests/core/ApprovalNamer.h"
#include "ApprovalTests/core/ApprovalWriter.h"
#include "ApprovalTests/core/FileApprover.h"
#include "ApprovalTests/core/Reporter.h"
#include "ApprovalTests/integrations/CheckFileMacroIsAbsolute.h"
#include "ApprovalTests/integrations/catch/Catch2Approvals.h"
#include "ApprovalTests/integrations/doctest/DocTestApprovals.h"
#include "ApprovalTests/integrations/google/GoogleConfiguration.h"
#include "ApprovalTests/integrations/google/GoogleCustomizationsFactory.h"
#include "ApprovalTests/integrations/google/GoogleTestApprovals.h"
#include "ApprovalTests/integrations/ut/UTApprovals.h"
#include "ApprovalTests/launchers/CommandLauncher.h"
#include "ApprovalTests/launchers/SystemLauncher.h"
#include "ApprovalTests/namers/ApprovalTestNamer.h"
#include "ApprovalTests/namers/DefaultNamerDisposer.h"
#include "ApprovalTests/namers/DefaultNamerFactory.h"
#include "ApprovalTests/namers/ExistingFileNamer.h"
#include "ApprovalTests/namers/HelpMessages.h"
#include "ApprovalTests/namers/NamerFactory.h"
#include "ApprovalTests/namers/SectionNameDisposer.h"
#include "ApprovalTests/namers/SeparateApprovedAndReceivedDirectoriesNamer.h"
#include "ApprovalTests/namers/SubdirectoryDisposer.h"
#include "ApprovalTests/reporters/AutoApproveIfMissingReporter.h"
#include "ApprovalTests/reporters/AutoApproveReporter.h"
#include "ApprovalTests/reporters/BlockingReporter.h"
#include "ApprovalTests/reporters/CIBuildOnlyReporter.h"
#include "ApprovalTests/reporters/CIBuildOnlyReporterUtils.h"
#include "ApprovalTests/reporters/ClipboardReporter.h"
#include "ApprovalTests/reporters/CombinationReporter.h"
#include "ApprovalTests/reporters/CommandReporter.h"
#include "ApprovalTests/reporters/ConvertForCygwin.h"
#include "ApprovalTests/reporters/CustomReporter.h"
#include "ApprovalTests/reporters/DefaultFrontLoadedReporter.h"
#include "ApprovalTests/reporters/DefaultReporter.h"
#include "ApprovalTests/reporters/DefaultReporterDisposer.h"
#include "ApprovalTests/reporters/DefaultReporterFactory.h"
#include "ApprovalTests/reporters/DiffInfo.h"
#include "ApprovalTests/reporters/DiffPrograms.h"
#include "ApprovalTests/reporters/DiffReporter.h"
#include "ApprovalTests/reporters/FirstWorkingReporter.h"
#include "ApprovalTests/reporters/FrontLoadedReporterDisposer.h"
#include "ApprovalTests/reporters/FrontLoadedReporterFactory.h"
#include "ApprovalTests/reporters/GenericDiffReporter.h"
#include "ApprovalTests/reporters/LinuxReporters.h"
#include "ApprovalTests/reporters/MacReporters.h"
#include "ApprovalTests/reporters/QuietReporter.h"
#include "ApprovalTests/reporters/TextDiffReporter.h"
#include "ApprovalTests/reporters/WindowsReporters.h"
#include "ApprovalTests/utilities/Blocker.h"
#include "ApprovalTests/utilities/CartesianProduct.h"
#include "ApprovalTests/utilities/ExceptionCollector.h"
#include "ApprovalTests/utilities/FileUtils.h"
#include "ApprovalTests/utilities/FileUtilsSystemSpecific.h"
#include "ApprovalTests/utilities/MachineBlocker.h"
#include "ApprovalTests/utilities/Macros.h"
#include "ApprovalTests/utilities/StringUtils.h"
#include "ApprovalTests/utilities/SystemUtils.h"
#include "ApprovalTests/utilities/WinMinGWUtils.h"
#include "ApprovalTests/writers/ExistingFile.h"
#include "ApprovalTests/writers/StringWriter.h"

#endif // APPROVALTESTS_CPP_APPROVALS_HPP
