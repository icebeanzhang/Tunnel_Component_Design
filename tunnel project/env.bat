SET "OCC_PATH=F:\Opencascade\OpenCASCADE-7.6.0-vc14-64\opencascade-7.6.0"
call "%OCC_PATH%\env.bat" %1 %2 %3

echo %OCC_PATH%\env.bat

set "BIN_DIR=win%ARCH%\%VCVER%\bind"
set "LIB_DIR=win%ARCH%\%VCVER%\libd"

if ["%CASDEB%"] == [""] (
  set "BIN_DIR=win%ARCH%\%VCVER%\bin"
  set "LIB_DIR=win%ARCH%\%VCVER%\lib"
)

set "PATH=%~dp0%LIB_DIR%;%~dp0%BIN_DIR%;%PATH%"