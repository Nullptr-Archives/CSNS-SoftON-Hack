#if !defined( TRIANGLEAPIH )
#define TRIANGLEAPIH
#pragma once

typedef enum 
{
	TRI_FRONT = 0,
	TRI_NONE = 1,
} TRICULLSTYLE;

#define TRI_API_VERSION		1

#define TRI_TRIANGLES		0
#define TRI_TRIANGLE_FAN	1
#define TRI_QUADS			2
#define TRI_POLYGON			3
#define TRI_LINES			4	
#define TRI_TRIANGLE_STRIP	5
#define TRI_QUAD_STRIP		6

typedef struct triangleapi_s
{
	int			version;

	void		( *RenderMode )( int mode );
	void		( *Begin )( int primitiveCode );
	void		( *End ) ( void );

	void		( *Color4f ) ( float r, float g, float b, float a );
	void		( *Color4ub ) ( unsigned char r, unsigned char g, unsigned char b, unsigned char a );
	void		( *TexCoord2f ) ( float u, float v );
	void		( *Vertex3fv ) ( float *worldPnt );
	void		( *Vertex3f ) ( float x, float y, float z );
	void		( *Brightness ) ( float brightness );
	void		( *CullFace ) ( TRICULLSTYLE style );
	int			( *SpriteTexture ) ( struct model_s *pSpriteModel, int frame );
	int			( *WorldToScreen ) ( float *world, float *screen );  // Returns 1 if it's z clipped
	void		( *Fog ) ( float flFogColor[3], float flStart, float flEnd, int bOn ); //Works just like GL_FOG, flFogColor is r/g/b.
} triangleapi_t;

#endif // !TRIANGLEAPIH
