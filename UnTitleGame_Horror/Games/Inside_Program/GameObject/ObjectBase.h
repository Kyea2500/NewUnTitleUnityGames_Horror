#pragma once
#include"../Dive/PosScaRotVel/Transform.h"
#include"../Dive/PosScaRotVel/Velocity.h"
#include <memory>

class ObjectBase
{
public:
	virtual ~ObjectBase();
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

private:
	std::shared_ptr<Transform> m_transform;
	std::shared_ptr<Velocity> m_velocity;
public:

	std::shared_ptr<Transform> GetTransform() const { return m_transform; }
	std::shared_ptr<Velocity> GetVelocity() const { return m_velocity; }

};