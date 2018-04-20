#pragma once

//-----------------------------------------------------
// Include Files
//-----------------------------------------------------
#include "GameEngine.h"
#include "ObjectBaseList.h"
#include "Player.h"
#include "RandomAgent.h"

//-----------------------------------------------------
// Box Class									
//-----------------------------------------------------
class Box: public ObjectBase
{
public:
	Box(DOUBLE2 pos);	// Constructor
	virtual ~Box();		// Destructor

	//-------------------------------------------------
	// Own methods								
	//-------------------------------------------------
	virtual void Tick(double deltaTime );
	virtual void Paint();
	virtual void CollideWith( ObjectBase *colliderptr, int otherType);
	void SetPlayerPtr(Player *playerPtr){m_PlayerPtr= playerPtr;}
	void SetPlayerPtr(RandomAgent *randPlayer){m_RandPlayer = randPlayer;}
private: 
	//-------------------------------------------------
	// Datamembers								
	//-------------------------------------------------
	int m_bulletsToShoot;

	int m_State;
	static const int STATE_NORMAL		= 0;
	static const int STATE_SHOOTING		= 1;
	static const int STATE_DESACTACTIVATE= 2;

	static Bitmap *m_BmpSpritePtr;

	double m_AnimationTik;
	Player *m_PlayerPtr;
	RandomAgent *m_RandPlayer;
	double m_DirRadians;
	DOUBLE2 m_PointingDir;
	double m_ShootCounter;
	int m_Lives;

	// -------------------------
	// Disabling default copy constructor and default 
	// assignment operator.
	// -------------------------
	Box(const Box& yRef);									
	Box& operator=(const Box& yRef);	
};