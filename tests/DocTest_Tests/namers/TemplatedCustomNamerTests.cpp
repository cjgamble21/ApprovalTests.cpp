#include "doctest/doctest.h"
#include "ApprovalTests/namers/TemplatedCustomNamer.h"
#include "ApprovalTests/Approvals.h"

using namespace ApprovalTests;

TEST_CASE("Test StringTemplates")
{
    // begin-snippet: templated_custom_namer_example
    TemplatedCustomNamer namer("/my/source/directory/{ApprovedOrReceived}/"
                               "{TestFileName}.{TestCaseName}.{FileExtension}");
    // end-snippet

    CHECK(namer.getApprovedFile(".txt") ==
          "/my/source/directory/approved/"
          "TemplatedCustomNamerTests.Test_StringTemplates.txt");
    CHECK(namer.getReceivedFile(".txt") ==
          "/my/source/directory/received/"
          "TemplatedCustomNamerTests.Test_StringTemplates.txt");
}

TEST_CASE("Test relative directory")
{
    TemplatedCustomNamer namer("{RelativeTestSourceDirectory}/{ApprovedOrReceived}/"
                               "{TestFileName}.{TestCaseName}.{FileExtension}");

    CHECK(namer.getApprovedFile(".txt") ==
          "namers/approved/"
          "TemplatedCustomNamerTests.Test_relative_directory.txt");
}

TEST_CASE("Test Namer Injection")
{
    // begin-snippet: templated_custom_namer_injection_via_options
    auto namer = TemplatedCustomNamer::create(
        "{TestSourceDirectory}/CustomName.{ApprovedOrReceived}.{FileExtension}");
    Approvals::verify("Hello", Options().withNamer(namer));
    // end-snippet

    // begin-snippet: templated_custom_namer_injection
    auto default_namer_disposer = TemplatedCustomNamer::useAsDefaultNamer(
        "{TestSourceDirectory}/CustomName.{ApprovedOrReceived}.{FileExtension}");
    // end-snippet

    Approvals::verify("Hello");
}

TEST_CASE("Test non-unique name")
{
    Approvals::verifyExceptionMessage([]() { TemplatedCustomNamer("hello.txt"); });
}

// ---- Docs
// TODO Revisit our documentation
// TODO Document ApprovalTestNamer::setCheckBuildConfig(false)
// TODO Document the details and limitations of each template string

// TODO Document scenarios where this might be useful (when run outside of build dir, e.g. embedded)
// TODO Make documentation example use different filenames for approved and received, for safety
