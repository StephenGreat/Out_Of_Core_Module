@echo off
echo ��Doxygen����ļ������utf-8ת����gbk
set path=%path%;"d:\\Desktop\\doxybat"

echo ����chm�����ļ�
call utf82gbk.bat index.hhp
call utf82gbk.bat index.hhc
call utf82gbk.bat index.hhk

