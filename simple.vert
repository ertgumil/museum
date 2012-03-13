//attribute vec4 gl_Color;
void main()
{
        //float postemp = gl_Position.z;
        gl_FrontColor = gl_Color;
        gl_Position = ftransform();

        //gl_Position.x = ftransform().y;
        //gl_Position.y = ftransform();
        //gl_Position.z = ftransform();

}
