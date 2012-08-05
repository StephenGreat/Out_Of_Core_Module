#ifndef _MAINPAGE_H_
#define _MAINPAGE_H_

/**
 * @mainpage Out Of Core Image Processing Liabary
 * 
 * @section intro_sec ����
 * ͨ����ͼ�����ǻ����ڴ���еģ�����ͼ�����ݷǳ������޷�������ȫ��װ���ڴ洦���ʱ�򣬻����ڴ�Ĵ������ͻ�ʧЧ��\n
 * Out Of Core���������������������⡣�����ݺܴ��ʱ��ʵ�ʵ����ݴ����Ӳ���ϣ�����Ҫ��ȡ���ߴ������ݵ�ʱ��
 *�ٶ�̬�ĴӴ����м������ݵ��ڴ���д���\n
 *
 * ��Ҫʵ�������漸���ࣺ
 * - BlockwiseImage �������ɴ��͵��������ݴ��棬�ṩ��ͼ�����ͨ���Խӿڣ�ͬʱ���Խ�ͼ������д�뵽�������Ա���������
 * - HierarchicalImage �̳���BlockwiseImage���ṩһ�µ�ͼ����ӿڣ����ڱ��浽����ʱ������ȡ��ͬ�Ĳ㼶��ͼ�����ݲ�д����̣����������Ժ���ȡ
 *��ͬ�ֱ����µ�ͼ�����ݡ�
 * - DiskBigImage ��������BlockwiseImage��HierarchicalImageд�뵽�����е�ͼ�����ݽ��ж�̬�Ķ�д������
 *
 * ���������ļ�˵����
 * - ReadingBigImage ͼ��������ĳ���ʵ�֡�
 * - Test ��BlockwiseImage��ͼ����ӿں�DiskBigImage�Ķ�д�ӿڽ����˲��ԣ�����һ�����ǹ��ڲ�ͬ���������Ĳ��ԡ�
 * - WriteBlockWiseImage ʹ��BlockwiseImageд��ͼ������
 * - WriteHierarchicalImage ʹ��HierarchicalImageд��ͼ������
 * \n
 * 
 * @section setup_sec ��װ
 * @subsection libary_sec ��ؿ�
 * <pre>
 * <b>1. boost</b>
 * ʹ�õ���boost����������ӿ⣺
 * data_time iostreams filesystem system thread
 * ��Ҫ���������ľ�̬��

 * <b>2. stxxl</b>
 * ��һ���ṩ�˻���stl�������ӿڣ�ͬʱ���������ݴ����Ӳ���еĿ⡣
 * Website : http://stxxl.sourceforge.net/ 
 * ��װ˵����
 * ��1����/SharedLibrary/stxxl/include ����Ϊͷ�ļ������ĵ�ַ
 * ��2����/SharedLibrary/stxxl/lib ����Ϊlib�����ĵ�ַ 
 * ��3���ڹ����ļ������������command line ��ǰ�����ú���boost, ������ stxxl�Ŀ��ʱ�� ���Զ�ȥ����boost����ؿ⣩

 * <b>Debug :</b>
 * C/C++ -- Command Line :
 * -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_SECURE_SCL=0 /Od /MDd /ZI -D_RTLDLL -DBOOST_LIB_DIAGNOSTIC -DSTXXL_BOOST_TIMESTAMP -DSTXXL_BOOST_CONFIG -DSTXXL_BOOST_FILESYSTEM -DSTXXL_BOOST_THREADS -DSTXXL_BOOST_RANDOM /EHsc /EHs /wd4820 /wd4217 /wd4668 /wd4619 /wd4625 /wd4626 /wd4355 /wd4996 -D_SCL_SECURE_NO_DEPRECATE /F 16777216 /nologo /DSTXXL_LIBNAME=\"stxxl_debug\" 

 * Linker -- Command Line :
 * /STACK:16777216 /NOLOGO /DEBUG 

 * <b>Release :</b>
 * C/C++ -- Command Line :
 * -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_SECURE_SCL=0 /O2 /Ob2 /MD /DNDEBUG -D_RTLDLL -DBOOST_LIB_DIAGNOSTIC -DSTXXL_BOOST_TIMESTAMP -DSTXXL_BOOST_CONFIG -DSTXXL_BOOST_FILESYSTEM -DSTXXL_BOOST_THREADS -DSTXXL_BOOST_RANDOM /EHsc /EHs /wd4820 /wd4217 /wd4668 /wd4619 /wd4625 /wd4626 /wd4355 /wd4996 -D_SCL_SECURE_NO_DEPRECATE /F 16777216 /nologo /DSTXXL_LIBNAME=\"stxxl_release\" 

 * Linker -- Command Line :
 * /STACK:16777216 /NOLOGO /OPT:REF 

 * ��4��stxxl�������ļ����ڴ������е�Ŀ¼�����½��ļ�config.stxxl
 * For example : #config.stxxl
 * disk=c:\stxxl,70000,wincall     
 * disk=d:\stxxl,70000,wincall
 * disk=e:\stxxl,70000,wincall
 * #��ʾ����c��d��e�зֱ���70000M��С���ļ�stxxl�������������á�
 * #����Out_Of_Coreģ����ԣ���Сȡ����ͼ������ݴ�С������һ��102400*102400��ͼ����ԣ�
 * ���ͼ����RGB����ʽ����ô�ܴ�СΪ30G��ͼ������ʹ����zorder���д洢�������������ࡣ
 * ʹ��zorder��Ϊ������ʽ�Ļ��������Ϊԭ����С��4����һ��Ϊ2�����ң����Է���60G��120G�ȽϺ��ʡ�

 * <b>3. OpenCV</b>
 * ��������˺� SAVE_MINI_IMAGE
 * �ڽ�ͼ��д�뵽�����е�ʱ��ͬʱҲ�����һ�����û�ָ���ֱ��ʴ�С��jpg��ʽͼ���ļ������ļ���ͼ�������ͼ��������õ���ʾЧ��
 * ��ʹ�õ���OpenCV������ģ��
 * core highgui imgproc
 * </pre>
 * @note Ĭ����û�ж���SAVE_MINI_IMAGE
 * \n
 * 
 * @section src_sec Out Of Coreģ�����
 * ���д��붼��ģ��������Ƿ���.h�ļ��е�inline������ֱ��include�������б��뼴�ɡ�\n
 * ���������/Platform/OutOfCore/include/ �ļ�����
 *
 */

#endif