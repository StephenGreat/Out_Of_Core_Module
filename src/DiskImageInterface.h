#ifndef _GIANT_HIERARCHICAL_INTERFACE_H
#define _GIANT_HIERARCHICAL_INTERFACE_H
#include "GiantImageInterface.h"
#include "UtlityFunc.h"

template<typename T>
class DiskImageInterface
{
public:
	/* pure virtual function */

	/*
	* @brief : ��ȡ�ƶ��ȼ�������ͼ������
	* @para start_row, start_col : ���������Ͻ�����
	* @para rows, cols : ������к��е���Ŀ
	* @para level �� ͼ��ķֱ��ʵȼ�
	* @para vec : ͼ������
	* @return : �Ƿ��ȡ�ɹ�
	*/
	virtual bool get_pixels_by_level(int level, int &start_row, int &start_col,
		int &rows, int &cols, std::vector<T> &vec) = 0;
	virtual bool set_pixel_by_level(int level, int start_row, int start_col, int rows, int cols, const std::vector<T> &vec) = 0;

    /*
	 *	@brief : get the current level image rows after calling the set_current_level function
	 */
	virtual size_t get_current_level_image_rows() const = 0;

	/*
	 *	@brief : get the current level image cols after calling the set_current_level function
	 */
	virtual size_t get_current_level_image_cols() const = 0;

    /*
	 *	@brief : set the image current level before any access to the hierarchical image data
	 */
	virtual bool set_current_level(int level) = 0;
	virtual size_t get_current_level() const = 0;

    /*
	 *	@brief : set the file cache number when loading image data since the image from disk
	 *	is too large so when load data from disk, using several file caches to save the image data for
	 *	improving I/O.
	 */
	virtual bool set_file_cache_number(int _file_cache_number) = 0;

	/*
	 *	@brief : get the maximum image level thus the minimal size image's scale level
	 */
	virtual size_t get_max_image_level() const = 0;
};

#endif