<!--
GENERATED FILE - DO NOT EDIT
This file was generated by [MarkdownSnippets](https://github.com/SimonCropp/MarkdownSnippets).
Source File: /doc/how_tos/mdsource/UseTheFmtLibraryToPrintObjects.source.md
To change this file edit the source file and then execute ./run_markdown_templates.sh.
-->

<a id="top"></a>

# How to Use the Fmt Library To Print Objects

<!-- toc -->
## Contents

  * [Introduction](#introduction)
  * [Usage](#usage)
  * [Installation](#installation)
    * [Bring your own](#bring-your-own)
    * [Set as default for Approvals](#set-as-default-for-approvals)<!-- endtoc -->

## Introduction

[{fmt}](https://fmt.dev/) is a useful library for printing objects with many default types formatted out of the box.

## Usage

Simply use `FmtApprovals::`

For example, vectors are not `ostream (<<)` printable by default. However, they are with {fmt}. so :

<!-- snippet: fmt_approvals -->
<a id='snippet-fmt_approvals'/></a>
```cpp
std::vector<int> numbers = {1, 2, 3};
FmtApprovals::verify(numbers);
```
<sup><a href='/tests/DocTest_Tests/integrations/FmtTests.cpp#L16-L19' title='File snippet `fmt_approvals` was extracted from'>snippet source</a> | <a href='#snippet-fmt_approvals' title='Navigate to start of snippet `fmt_approvals`'>anchor</a></sup>
<!-- endsnippet -->

This will produce the following output:

<!-- snippet: FmtTests.FmtContainers.approved.txt -->
<a id='snippet-FmtTests.FmtContainers.approved.txt'/></a>
```txt
{1, 2, 3}
```
<sup><a href='/tests/DocTest_Tests/integrations/approval_tests/FmtTests.FmtContainers.approved.txt#L1-L1' title='File snippet `FmtTests.FmtContainers.approved.txt` was extracted from'>snippet source</a> | <a href='#snippet-FmtTests.FmtContainers.approved.txt' title='Navigate to start of snippet `FmtTests.FmtContainers.approved.txt`'>anchor</a></sup>
<!-- endsnippet -->

**note:** it is important that we included fmt before approvaltests.

<!-- snippet: fmt_includes -->
<a id='snippet-fmt_includes'/></a>
```cpp
#include <fmt/ranges.h>
```
<sup><a href='/tests/DocTest_Tests/integrations/FmtTests.cpp#L5-L8' title='File snippet `fmt_includes` was extracted from'>snippet source</a> | <a href='#snippet-fmt_includes' title='Navigate to start of snippet `fmt_includes`'>anchor</a></sup>
<!-- endsnippet -->

## Installation

### Bring your own

ApprovalTests assumes you will add the {fmt} library **before** including `ApprovalTests.hpp`. As such it makes no assumptions about fmt. We suggest you read [their docs](https://fmt.dev/latest/usage.html).

If you would like to see how we added fmt to our build, check out:

<!-- snippet: fmt_cmake -->
<a id='snippet-fmt_cmake'/></a>
```txt
target_link_libraries(${PROJECT_NAME} fmt::fmt)
```
<sup><a href='/tests/DocTest_Tests/CMakeLists.txt#L47-L49' title='File snippet `fmt_cmake` was extracted from'>snippet source</a> | <a href='#snippet-fmt_cmake' title='Navigate to start of snippet `fmt_cmake`'>anchor</a></sup>
<!-- endsnippet -->

[fmt/CmakeList.txt](/CMake/fmt/CMakeLists.txt)  

[fmt/CmakeList.txt.in](/CMake/fmt/CMakeLists.txt.in)

### Set as default for Approvals

If you wish, you can set FmtApprovals to be the default Approvals with the following line before including `ApprovalTests.hpp`

<!-- snippet: fmt_set_as_default -->
<a id='snippet-fmt_set_as_default'/></a>
```cpp
#define APPROVAL_TESTS_DEFAULT_STREAM_CONVERTER FmtToString
```
<sup><a href='/tests/DocTest_Tests/integrations/FmtAsDefaultTests.cpp#L5-L7' title='File snippet `fmt_set_as_default` was extracted from'>snippet source</a> | <a href='#snippet-fmt_set_as_default' title='Navigate to start of snippet `fmt_set_as_default`'>anchor</a></sup>
<!-- endsnippet -->


---

[Back to User Guide](/doc/README.md#top)