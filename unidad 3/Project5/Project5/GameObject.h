#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

typedef struct {
    float x, y;
    float width, height;
} GameObject;

void GameObject_init(GameObject* obj, float x, float y, float width, float height);

#endif // GAMEOBJECT_H
