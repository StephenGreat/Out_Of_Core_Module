#include "readingbigimage.h"
#include "qbigimagewidget.h"
#include "docklabel.h"

#include <Qtgui/QMessageBox>
#include <Qtgui/QFileDialog>
#include <Qtgui/QMouseEvent>
#include <Qtgui/QPaintEvent>
#include <Qtgui/QPixmap>
#include <Qtgui/QPainter>
#include <QtGui/QDockWidget>
#include <QtGui/QLabel>
#include <QtGui/QPicture>
#include <QtCore/QFileInfo>

#include <iostream>
using namespace std;

ReadingBigImage::ReadingBigImage(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

    m_windowname = tr("Reading Big Image");
	m_central_widget = new QBigImageWidget(this);
	setCentralWidget(m_central_widget);
	setStatusBar(NULL);

	connect(ui.m_action_open_file, SIGNAL(triggered()), this, SLOT(on_open_file_name()));

    setWindowTitle(m_windowname);

    m_dock_widget = new QDockWidget(QString::fromLocal8Bit("����ͼ"), this);
}

ReadingBigImage::~ReadingBigImage()
{

}

void ReadingBigImage::on_open_file_name()
{
    open_file_name(QFileDialog::getOpenFileName(this, "Open Bigimage File", ".", "*.bigimage"));
    return;
}

void ReadingBigImage::mouseMoveEvent(QMouseEvent * event)
{

}

void ReadingBigImage::mousePressEvent(QMouseEvent * event)
{

}

void ReadingBigImage::mouseReleaseEvent(QMouseEvent * event)
{

}

void ReadingBigImage::paintEvent(QPaintEvent * event)
{

}

void ReadingBigImage::resizeEvent(QResizeEvent * event)
{

}

void ReadingBigImage::open_file_name(QString file_name)
{
    /* if get the reasonable file name */
    if(!file_name.isEmpty()){

        try {

            /* if load_image failure */
            if(!m_central_widget->load_image(file_name)) {
                QString err_info = QString::fromLocal8Bit("��ȡͼ���ļ� ") + file_name + QString::fromLocal8Bit(" ʧ��\n")
                    + QString::fromLocal8Bit("���ܶ����˴����ͼ���ļ�������ͼ�����ݶ�ʧ������������ָ��");
                QMessageBox::warning(this, "ReadingBigImage", err_info);
                return;
            }
            
            setWindowTitle(m_windowname + " - " + file_name);

            QString small_image_path = QFileInfo(file_name).dir().absolutePath() + "/" + QFileInfo(file_name).baseName() + ".jpg";
            std::cout << small_image_path.toStdString() << std::endl;
            if(!QFile::exists(small_image_path)) {
                QMessageBox::information(this, tr("Information"), QString::fromLocal8Bit("����������ͼ"), QMessageBox::Ok);
                return;
            }

            /* now read the small image into the dock widget */
            int small_part_size = 120;
            m_dock_label = new DockLabel(m_dock_widget);
            m_dock_label->setMargin(10);
            connect(m_central_widget, SIGNAL(signal_rect_ratio(double,double,double,double)),
                m_dock_label, SLOT(set_draw_rect_ratio(double,double,double,double)));

            QPixmap pixmap(small_image_path);
            if(pixmap.width() > pixmap.height()) {
                m_dock_label->setPixmap(pixmap.scaledToHeight(small_part_size));
                m_dock_widget->setWidget(m_dock_label);
                m_dock_widget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
                addDockWidget(Qt::TopDockWidgetArea, m_dock_widget);
            } else {
                m_dock_label->setPixmap(pixmap.scaledToWidth(small_part_size));
                m_dock_widget->setWidget(m_dock_label);
                m_dock_widget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
                addDockWidget(Qt::LeftDockWidgetArea, m_dock_widget);
            }

            /* exists the bad_alloc exception */
        } catch (std::bad_alloc &err) {
            QString err_info = QString::fromLocal8Bit("�ڴ����ʧ��\n�����ڴ治�㵼��"); 
            if(QMessageBox::Abort == QMessageBox::critical(this, "ReadingBigImage", err_info, 
                QMessageBox::Ok | QMessageBox::Abort, QMessageBox::Ok)) {
                    this->close();
            }
        }
    }
}
