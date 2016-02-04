@echo off

set CUR_DIR=%cd%

md get_only_mark

for %%a in (*.nmf) do (
	cnmf getall %%a MARK >get_only_mark\%%a
)
