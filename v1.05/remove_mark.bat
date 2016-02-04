@echo off

set CUR_DIR=%cd%

md remove_mark_log

for %%a in (*.nmf) do (
	cnmf getnll %%a MARK >remove_mark_log\%%a
)
