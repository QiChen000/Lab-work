#ifdef GL_E5
precision mediump float;
#endif

uniform mat4 modelViewProjectionMatrix;

attribute vec4 position;

void main(){
	gl_Position = modelViewProjectionMatrix * position;
}
