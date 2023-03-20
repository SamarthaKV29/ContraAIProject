void AIAgentPlayer::Seek_Destroy(double deltaTime){

	struct enemy{
		int e_type;
		DOUBLE2 pos;
		DOUBLE2 distPlayer;
	};
	vector<enemy> enemies;

	for(int i = 0; i < (int)m_ObjectListPtr->getObjectCount(); i++){
		if(m_ObjectListPtr->CheckIfPlaatsExist(i)){
			ObjectBase *curr = m_ObjectListPtr->GetPointer(i);
			if(curr->GetType() == TYPE_ENEMY || curr->GetType() == TYPE_ENEMY_BOX || curr->GetType() == TYPE_ENEMY_WALKING || curr->GetType() == TYPE_POWERUP || curr->GetType() == TYPE_ENEMY_BULLET){
				enemy e;
				e.e_type = curr->GetType();
				e.pos = curr->GetPos();
				e.distPlayer = m_Pos - e.pos;
				enemies.push_back(e);
			}
			enemy nearest = enemies.at(0);
			for(int i =1; i < (int)enemies.size() - 5; i++){
				if(enemies.at(i).distPlayer.x > nearest.distPlayer.x){
					nearest = enemies.at(i);
				}
			}
			*currEnemy = nearest.distPlayer;

			if(nearest.e_type == TYPE_ENEMY_WALKING || nearest.e_type == TYPE_ENEMY || nearest.e_type == TYPE_ENEMY_BOX || nearest.e_type == TYPE_POWERUP){
				m_PointingDir.x = nearest.distPlayer.x/nearest.distPlayer.x;
				m_PointingDir.y = nearest.distPlayer.y/nearest.distPlayer.y;
				if(m_PointingDir.x < 0){
					M_MOVINGRIGHT = true;
				}
				else if(m_PointingDir.x > 0){
					M_MOVINGLEFT = true;
				}
				else{
					M_MOVINGRIGHT = false;
					M_MOVINGLEFT = false;
					m_PointingDir.x = 0;
				}
				if(m_PointingDir.y < 0)
					M_LOOKINGUP = true;
				else
					M_LOOKINGDOWN = true;
			}
			if(currEnemy->x < 0){
				if(m_PointingDir.x = -m_PointingDir.x) m_PointingDir.x = -m_PointingDir.x;
				m_Velocity.x= WALKSPEED * m_PointingDir.x;
			}
			if(currEnemy->y == 0){
				m_BulletDir = DOUBLE2(m_PointingDir.x, 0);
			}
			else if(currEnemy->x == 0){
				m_BulletDir = DOUBLE2(0, m_PointingDir.y);
			}
  			else if(currEnemy->x > 0){
				m_PointingDir.x = -m_PointingDir.x;
				m_Velocity.x= WALKSPEED * m_PointingDir.x;
			}


			m_BulletDir = m_PointingDir;
			if(m_State == STATE_NORMAL){
					++m_ShootCounter;if(m_ShootCounter >= 500)m_State= STATE_SHOOTING;
			}
			else if(m_State == STATE_SHOOTING){
				--m_ShootCounter; // Switch systeem
				if( m_ShootCounter<=0 ) m_State= STATE_NORMAL;
				Shoot(true);
			}
			}
	}
}
