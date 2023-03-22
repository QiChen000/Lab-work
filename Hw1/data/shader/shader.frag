#ifdef GL_E5
precision mediump float;
#endif

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;


void main()
{
    vec2 coord = gl_FragColor.xy;
    vec3 coord = vec3(0.0);
    color.r = 0.6;
	gl_FragColor = vec4(color,1.0);
}
