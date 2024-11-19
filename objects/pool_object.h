#pragma once
#include <scene_object.h>
#include <global_2d.h>

class pool_object : public SceneObject
{
    Q_OBJECT
public:
    explicit pool_object(const Global2d center, QObject* parent = nullptr);
    void paint(Orentation* orentation, QPainter* painter) override;
    QList<Local2d> pool_ ;
    Global2d center_;
};

