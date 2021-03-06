#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "CloudsVisualSystem.h"


class FlowParticle {
  public:
	FlowParticle(){
		index = 0;
		dead = false;
	}
	ofVec3f pos;
	int index;
	bool dead;
};

class CloudsVisualSystemVectorFlow : public CloudsVisualSystem {
public:
	
	CloudsVisualSystemVectorFlow();
	
	string getSystemName();
    
    void selfSetup();
    void selfSetupGuis();
    
    void selfUpdate();
    void selfDrawBackground();
    void selfDrawDebug();
    void selfSceneTransformation();
	void selfPresetLoaded(string presetPath);
	
    void selfDraw();
    void selfExit();
    void selfBegin();
	void selfEnd();
    
    void selfKeyPressed(ofKeyEventArgs & args);
    void selfKeyReleased(ofKeyEventArgs & args);
    
    void selfMouseDragged(ofMouseEventArgs& data);
    void selfMouseMoved(ofMouseEventArgs& data);
    void selfMousePressed(ofMouseEventArgs& data);
    void selfMouseReleased(ofMouseEventArgs& data);
    
    void selfSetupGui();
    void selfGuiEvent(ofxUIEventArgs &e);
    
    void selfSetupSystemGui();
    void guiSystemEvent(ofxUIEventArgs &e);
    
    void selfSetupRenderGui();
    void guiRenderEvent(ofxUIEventArgs &e);
	
protected:
	
	vector<FlowParticle> particles;
	
	int maxVertices;
	ofVboMesh particleMesh;
	ofVboMesh lines;
	int trailLength;
	float generateTrailLength;
	float generateMaxVerts;
	float particlesPerFrame;
	
	void addParticle();
	
	ofVec3f getDirection(float x, float y);
//	float getMagnitude(float x, float y);
	float sampleField(float x, float y);
	
	void initFlowField();
	bool regenerateFlow;
	float step;
	float chaos;
	float chaos2;
	float speed;	
	float speed2;
	float fieldAmplitude;
	int width, height;
	float maxLength;
	

	float oscFrequency;
	float oscAmp;
	
	ofImage colorMap;
	ofFloatColor startColor;
	ofFloatColor endColor;
	bool interpRGB;
	bool blendAdd;
	
	ofVec2f sincPosition;
	float sincRadius;
	void getSincSourceAngle(int x, int y, float& angle, float& weight);
	

	float fieldAlpha;
};