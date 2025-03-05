#include "qfaceobject.h"

QFaceObject::QFaceObject(QObject *parent) : QObject(parent)
{
    //初始化
    seeta::ModelSetting FDmode("/home/wodefa/AttendenceServer/model/fd_2_00.dat", seeta::ModelSetting::CPU, 0);
    seeta::ModelSetting PDmode("/home/wodefa/AttendenceServer/model/pd_2_00_pts5.dat",seeta::ModelSetting::CPU, 0);
    seeta::ModelSetting FRmode("/home/wodefa/AttendenceServer/model/fr_2_10.dat",seeta::ModelSetting::CPU, 0);
    this->fengpinptr = new seeta::FaceEngine(FDmode, PDmode, FRmode);
    //导入已有的数据库
    this->fengpinptr->Load("./face.db");
}
QFaceObject::~QFaceObject(){
    delete fengpinptr;
}

int64_t QFaceObject::face_register(cv::Mat &faceImage)
{
    //把opencv的Mat数据转为seetaface的数据
    SeetaImageData simage;
    simage.data = faceImage.data;
    simage.width = faceImage.cols;
    simage.height = faceImage.rows;
    simage.channels = faceImage.channels();
    int64_t faceid = this->fengpinptr->Register(simage);//返回注册一个人脸id
    if(faceid >= 0){
        fengpinptr->Save("./face.db");
    }
    return faceid;
}

int QFaceObject::face_query(cv::Mat &faceImage)
{
    //把opencv的Mat数据转为seetaface的数据
    SeetaImageData simage;
    simage.data = faceImage.data;
    simage.width = faceImage.cols;
    simage.height = faceImage.rows;
    simage.channels = faceImage.channels();
    float similarity = 0;
    int64_t faceid = fengpinptr->Query(simage, &similarity);
    if(similarity > 0.7)
    {
       emit send_faceid(faceid);
    }else
    {
        emit send_faceid(-1);
    }
    return faceid;
}
