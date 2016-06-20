# cmake-supporter-sample

Sample to use cmake-supporter. This repository has a didactic purpose. This is a
sample how works cmakesupporter using a cxx project template.

## Instructions

1º Clone with submodules:

> git clone --recursive git://github.com/vgonisanz/cmake-supporter-sample

2º Configure with CMake

3º Build.

## Must to create javascript to generate automatically from cmakesupporter templates and user info:

Design to automatically generate projects:
- Note: cmakesupporter as submodule or as hardcode?
- Check list with modules, samples, test, 3rdparty, cmake to create or not.
- Module list: List of libraries to create with templates.
- Sample list: List of executable to create samples.
- Test list: List of test to create test modules (TODO in cmakesupporter templates).
- Optional: 3rdparty list.
- Optional: Add a namespace to all modules (threemonkeybits in this case)

## Create your own repository with custom folders

Each folder must have proper files. In example:

- *modules*:  All repository libraries (Source code).
- *samples*:  All binaries to show how use modules (Source code)
- *test*:     All unit test to check proper behavoir (Source code)
- *3rdParty*: All external code or submodules needed by your repository.
- *cmake*:    All cmake scripts (Modules, etc)    

Main folder must content essential files.

- *CMakeLists.txt*  Main project configuration, used in all other sub projects.
- *LICENSE*         Project LICENSE
- *README.md*       Instruccions
- *.gitignore*      Exclude instruction for git
- *.gitsubmodule*   Info submodules
- *.git*            git data
- *other*           Add needed files that cannot be anywhere
