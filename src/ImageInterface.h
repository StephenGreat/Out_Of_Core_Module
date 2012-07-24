#ifndef _IMAGE_INTERFACE_H
#define _IMAGE_INTERFACE_H

#include <string>
#include <vector>

#include "DataType.h"

template<typename T>
class ImageInterface
{
public:

    /*
     * @brief : ��ʼ��ͼ��ĳ���
     * @para width, height �� ����
     * @return : �Ƿ񷵻سɹ�
     */
	virtual bool init(size_t rows, size_t cols) = 0;

    /*
     * @brief : ���ͼ������
     */
	virtual bool reset() = 0;

    /*
     * @brief : д��ͼ��
     * @para file_name : ͼ�������
     * @return : �Ƿ�д��ɹ�
     */
	virtual bool write_image(const char* file_name) = 0;
	virtual bool write_image(const std::string &file_name) = 0;

    /*
     * @brief : ��ȡ���꣨x,y)λ��ͼ������
     * @para x,y : ͼ������λ��
     * @return : ͼ�����ݵ�����
     */
	virtual T& get_pixel(int row, int col) = 0;
	virtual const T& get_pixel(int row, int col) const = 0;
	virtual T& operator() (int row, int col) = 0;
	virtual const T& operator() (int row, int col) const = 0;

    /*
     * @brief : ��ȡ����ͼ������
     * @para min_row, max_row : �����е����귶Χ
     * @para min_col, max_col : �����е����귶Χ
     * @para ptr �� ͼ������ָ��
     * @return : �Ƿ��ȡ�ɹ�
     */
	virtual bool get_pixel(int min_row, int max_row, int min_col, int max_col, T* ptr) const = 0;
	virtual bool set_pixel(int min_row, int max_row, int min_col, int max_col, const T* ptr) = 0;

    /*
     * @brief : ��ȡ����ͼ������
     * @para min_row, max_row : �����е����귶Χ
     * @para min_col, max_col : �����е����귶Χ
     * @para data �� ͼ����������
     * @return : �Ƿ��ȡ�ɹ�
     */
	virtual bool get_pixel(int min_row, int max_row, int min_col, int max_col, std::vector<T> &data) const = 0;
	virtual bool set_pixel(int min_row, int max_row, int min_col, int max_col, const std::vector<T> &data) = 0;

public:
	size_t get_image_cols() const { return img_size.cols; }
	size_t get_image_rows() const { return img_size.rows; }

protected:
	Size img_size;
};

#endif