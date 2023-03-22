#pragma once
#include "ofMain.h"

class bird {
public:
	bird(vector<bird>* const, const int, ofColor, vector<bird>* const, vector<bird>* const, vector<bird>* const);
	virtual ~bird();

	virtual void update();
	virtual void draw();

	int id;
	float Size;
    float head;

    
	ofVec2f pos;
	ofVec2f vel;
	ofVec2f acc;
	ofColor ourColor;

protected:
	vector<bird>* pSelfGroup;
	vector<bird>* pEnemyGroup;
	vector<bird>* pFriendGroup;
	vector<bird>* pFriendGroup2;

	ofVec2f separationVel; 
	ofVec2f alignmentVel;
	ofVec2f cohesionVel;
	ofVec2f groupCenterPos;
};
