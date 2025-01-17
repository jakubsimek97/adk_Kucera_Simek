#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include "qpoint3d.h"
#include <QtGui>
#include "edge.h"
#include "triangle.h"


class Draw : public QWidget
{
    Q_OBJECT
private:
    std::vector<QPoint3D> points;
//    std::vector<QPoint3D> csv_points;
    std::vector<Edge> dt;
    std::vector<Edge> contours;
    std::vector<Edge> contours_main;
    std::vector<Edge> contours_labeled;
    std::vector<Triangle> triangles;
    int dz;
    int k;
    double om;
    int z_min, z_max;
    double scale;
    double trans_x, trans_y;
    int offset_x, offset_y;
    QString set_col;
    QString method;
    bool contoursUp;
    bool invert;
    bool dmtUp = false;
    double maxSlope;
    double minSlope;

public:
    //Drawing
    explicit Draw(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void clearPoints(){points.clear();} // csv_points.clear();}
    void clearDT(){dt.clear();}
    void clearContours(){contours.clear(); contours_labeled.clear(); contours_main.clear();}
    void clearTriangles(){triangles.clear();}
    void generateShapes();
    void drawCSVPoints(std::vector<QPoint3D> &points_3d);

    //Getters
    std::vector<QPoint3D> getPoints(){return points;}
//    std::vector<QPoint3D> getCSVPoints(){return csv_points;}
    std::vector<Edge> getDT(){return dt;}    
    std::vector<Edge> getContours(){return contours;}
    std::vector<Edge> getContoursMain(){return contours_main;}
    std::vector<Triangle> getTriangles(){return triangles;}
    std::vector<Edge> getContoursLabeled(){return contours_labeled;}
    int getZMin(){return z_min;}
    int getZMax(){return z_max;}
    double getScale(){return scale;}
    double getTransX(){return trans_x;}
    double getTransY(){return trans_y;}
    int getDeltaX(){return offset_x;}
    int getDeltaY(){return offset_y;}
    int getContourInterval(){return k;}

    //Setters
    void setDT(std::vector<Edge> &dt_){dt = dt_;}
    void setPoints(std::vector<QPoint3D> &points_){points = points_;}   
    void setTriangles(std::vector<Triangle> &triangles_){triangles = triangles_;}
    void setRotate(double om_){om=(om_*M_PI)/180;};
    void setContours(std::vector<Edge> &contours_){contours = contours_;}
    void setContoursMain(std::vector<Edge> &contours_main_){contours_main = contours_main_;}
    void setdZ(int dz_){dz=dz_;}
    void setK(int k_){k=k_;}
    void setz_min(int zmin_){z_min=zmin_;}
    void setz_max(int z_max_){z_max=z_max_;}
    void setColor(QString &color_){set_col = color_;}
    void setCSVPoints(std::vector<QPoint3D> &csv_points){points.insert(points.end(), csv_points.begin(), csv_points.end());}
    void setScale(double &scale_){scale = scale_;}
    void setTrans(double &trans_x_, double &trans_y_){trans_x = trans_x_; trans_y = trans_y_;}
    void setOffsets(int &offset_x_, int &offset_y_){offset_x = offset_x_; offset_y = offset_y_;}
    void setContoursLabeled(std::vector<Edge> &contours_labeled_){contours_labeled=contours_labeled_;}
    void setAnalyzeMethod(QString method_){method = method_;}
    void setContourUp(bool contoursUp_ ) {contoursUp = contoursUp_;}
    void setInvert(bool invert_ ) {invert = invert_;}
    void setDmtUp(bool dmtUp_) {dmtUp = dmtUp_;}
    void setMaxSlope(double max) {maxSlope = max;}
    void setMinSlope(double min) {minSlope = min;}

signals:

public slots:
};

#endif // DRAW_H
