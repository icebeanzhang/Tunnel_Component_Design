@echo off

Setlocal EnableDelayedExpansion

rem Setup environment
rem 配置相应参数，%3默认是release 可手动修改为debug
call "%~dp0env.bat" vc14 win64 %3 

rem 修改项目名称
call "OccQt_Rep.pro"
