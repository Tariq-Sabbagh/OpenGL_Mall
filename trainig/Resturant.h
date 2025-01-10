

extern void drawStructure(int image,int image2);

extern void drawDoor(float d, int image);

extern void DrawStructureFloor(int image);

extern void DrawStructureGlass(float x,float y,float z,float x1,float y1,float z1,int image);

extern void DrawStructurebeu(int image);

extern void DrawGround(float x,float y,float z,float x1,float y1,float z1,int image);

extern void DrawResturant(int floorTexture ,int fixglass ,int glassTexture,int screen,int doorTexture, int wallRe,int chairTexture,int tableTexture,int tablelegTextur,int fruitcone,int fenceTexture,int flowresTexture,int grass,int logoTexture );

extern void table(float x, float y, float z, float w, float h, float d,int tableTexture,int tablelegTexture);

extern void parallel_rectangles(float x, float y, float z, float w, float h, float d, int texture);

extern void rectangleYZ(float x, float y, float z, float w, float h, int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu); 
extern void  rectangleXZ(float x, float y, float z, float w, float h,int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu);
extern void rectangleXY(float x, float y, float z, float w, float h,int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu);

extern void chair(float x, float y, float z,int texture);


extern void cone(float x, float y, float z, float h, float r, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu);

extern void drawFence(float startX, float startY, float startZ, int numPlanks, float plankWidth, float plankHeight, float plankDepth, float spacing,int texture);

extern void drawPlank(float x, float y, float z, float width, float height, float depth,int texture);

extern void DrawTableChair(int texture1,int texture2,int texture3);

extern void drawDecore(int texture1,int texture2, int texture3,int texture4);

void DrawStructureGlass(float x,float y,float z,float x1,float y1,float z1,int image,int f,int c);