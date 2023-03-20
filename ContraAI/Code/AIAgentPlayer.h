#pragma once

//-----------------------------------------------------
// Include Files
//-----------------------------------------------------
#include "GameEngine.h"
#include "ObjectBaseList.h"
#include "Bridge.h"
#include "GameScore.h"
#include "Bullet.h"
#include "GameWinMain.h"
#include <sstream>
#include <map>
#include <time.h>
#include <algorithm>

//-----------------------------------------------------
// AIAgentPlayer Class									
//-----------------------------------------------------
class AIAgentPlayer: public ObjectBase
{

public:
	AIAgentPlayer( int x, int y);	// Constructor
	virtual ~AIAgentPlayer();		// Destructor

	//-------------------------------------------------
	// Own methods								
	//-------------------------------------------------
	void Jump(int force);
	virtual void Tick(double deltaTime);
	virtual void Paint();
	virtual void CollideWith( ObjectBase *colliderptr, int team);

	void SetGlobalVars( ObjectList *objectListPtr, DOUBLE2 LevelMax);
	void SetPowerup( int bulletType ) { 
		if( bulletType != BULLET_R )m_BulletType= bulletType; 
		if( bulletType == -1 ) DebugBreak();
	}
	virtual DOUBLE2 GetPos(){ return m_CenterPos; }
	
	void AddLevelHitRegion( HitRegion *levelHit ){
		m_LevelHitRegions.push_back(levelHit);
	}
	String GetEnemyDetails();
	//----------------------------------------------------
	bool M_MOVINGLEFT;
	bool M_MOVINGRIGHT;
	bool M_LOOKINGUP;
	bool M_LOOKINGDOWN;
	bool M_JUMPING;
	bool M_STOPPED;
	bool M_DUCKING;
	bool M_SHOOTING;
	//bool M_JUMPINGDOWN;
	void setBoolsFalse(){
		M_MOVINGLEFT = false;
		M_MOVINGRIGHT= false;
		M_LOOKINGUP= false;
		M_LOOKINGDOWN= false;
		M_JUMPING= false;
		M_STOPPED= false;
		M_DUCKING= false;
		M_SHOOTING= false;
		//M_JUMPINGDOWN= false;
	}
    void Seek_();

private: 
	
	//-------------------------------------------------
	// Datamembers
	//-------------------------------------------------

	// Power up's constants
	int m_BulletType;
	static const int BULLET_NORMAL		= 0;
	static const int BULLET_MITRAILLEUR	= 1;
	static const int BULLET_SUPER		= 2;
	static const int BULLET_LAZER		= 3;
	static const int BULLET_FLAME		= 4;
	static const int BULLET_R			= 5; // Score ofzo?
	DOUBLE2 currEnemy;
	/// VOOR DE SPRITES ///
	int m_State;
	static const int STATE_NORMAL= 0;
	static const int STATE_CRAWL = 1;
	static const int STATE_JUMP  = 2;
	static const int STATE_SWIM  = 3;
	static const int STATE_DIVE  = 4;
	static const int STATE_DIE   = 5;
	static const int STATE_DEAD  = 5;
	

	//-----------------------------------------------------------------------
	vector<int> actions;
	vector<DOUBLE2> states;
    static Bitmap *m_BmpSpritePtr;
	DOUBLE2 m_BodySize, m_LegsSize, m_BBoxSize;
	//MATRIX3X2 *m_MatViewPtr;
	double m_LegsFrame;
	int m_BodyFrame;
	double m_JumpRotation;
	DOUBLE2 m_CenterPos;
	static const int WALKSPEED= 100;
	bool m_ControlsOn;
	double m_InvincebleTimer;

	bool m_AutomaticFinalRun; // vk_right
	int m_cnt;
	int m_Lives;
	double m_TimeToDie;

	/// VOOR DE COLITIONS ///
	bool m_OnGround;

	HitRegion /*m_HitBBox, */*m_HitBBoxH, *m_HitBBoxV;
	//HitRegion *m_HitTerrainPtr;
	vector<HitRegion*> m_LevelHitRegions;
	bool m_Colide;
	DOUBLE2 m_Velocity, m_LevelMax, m_PointingDir, m_BulletSpawn;
	DOUBLE2 m_BulletDir;
    struct enemy{
        int type;
        DOUBLE2 pos;
    };
	ObjectList *m_ObjectListPtr;
	vector<enemy> m_Enemies;
	vector<DOUBLE2> m_Bullets;

	double m_ShootCounter;
	
	// Funks -----------------------------
	bool DoCollitions(HitRegion *hitVertPtr, DOUBLE2& pos, DOUBLE2& velocity, HitRegion *levelHitPtr);
	double ReturnGoodLen(double getal1, double getal2, double centerXY);
	void DrawAIAgentPlayer();
	void StartToDie();
	void DieAndRespawn();
	void CalculateStateAndFrame();
	void CalculateStateAndFrameAI();
	void CalculateBulletSpawn();
	void Shoot();
	
	// -------------------------
	// Disabling default copy constructor and default 
	// assignment operator.
	// -------------------------
	AIAgentPlayer(const AIAgentPlayer& yRef);									
	AIAgentPlayer& operator=(const AIAgentPlayer& yRef);	
};
	

//------------------------------------//
	
	
	


//------------------------------------//