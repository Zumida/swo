@echo off
setlocal
call setenv.bat
pushd src & mingw32-make %* & popd
