#include "Font.h"

Font::Font()
{
    UnsupportedChar = new FontChar(3, 6, 0, 252783);
    
    Chars = new FontChar*[255];

    // Unsupported chars: 0-31
    for (int i=0; i<=31; ++i)
        Chars[i] = UnsupportedChar;

    Chars[32] = new FontChar(2, 1, 0, 0); //  
    Chars[33] = new FontChar(1, 5, 1, 23); // !

    // Unsupported chars: 34-43
    for (int i=34; i<=43; ++i)
        Chars[i] = UnsupportedChar;

    Chars[44] = new FontChar(2, 2, 5, 6); // ,
    Chars[45] = new FontChar(3, 1, 3, 7); // -
    Chars[46] = new FontChar(1, 1, 5, 1); // .
    Chars[47] = UnsupportedChar; // /
    Chars[48] = new FontChar(4, 5, 1, 432534); // 0
    Chars[49] = new FontChar(2, 5, 1, 683); // 1
    Chars[50] = new FontChar(4, 5, 1, 988807); // 2
    Chars[51] = new FontChar(4, 5, 1, 493191); // 3
    Chars[52] = new FontChar(4, 5, 1, 324964); // 4
    Chars[53] = new FontChar(4, 5, 1, 493343); // 5
    Chars[54] = new FontChar(4, 5, 1, 431894); // 6
    Chars[55] = new FontChar(4, 5, 1, 140431); // 7
    Chars[56] = new FontChar(4, 5, 1, 431766); // 8
    Chars[57] = new FontChar(4, 5, 1, 429718); // 9

    // Unsupported chars: 58-59
    for (int i=58; i<=59; ++i)
        Chars[i] = UnsupportedChar;

    Chars[60] = new FontChar(3, 5, 1, 17492); // <
    Chars[61] = UnsupportedChar; // =
    Chars[62] = new FontChar(3, 5, 1, 5393); // >
    Chars[63] = new FontChar(4, 5, 1, 132743); // ?
    Chars[64] = UnsupportedChar; // @
    Chars[65] = new FontChar(4, 5, 1, 653718); // A
    Chars[66] = new FontChar(4, 5, 1, 497559); // B
    Chars[67] = new FontChar(3, 5, 1, 25166); // C
    Chars[68] = new FontChar(4, 5, 1, 498071); // D
    Chars[69] = new FontChar(3, 5, 1, 29647); // E
    Chars[70] = new FontChar(3, 5, 1, 5071); // F
    Chars[71] = new FontChar(4, 5, 1, 957726); // G
    Chars[72] = new FontChar(4, 5, 1, 630681); // H
    Chars[73] = new FontChar(3, 5, 1, 29847); // I
    Chars[74] = UnsupportedChar; // J
    Chars[75] = new FontChar(4, 5, 1, 611161); // K
    Chars[76] = new FontChar(3, 5, 1, 29257); // L
    Chars[77] = new FontChar(5, 5, 1, 18405233); // M
    Chars[78] = new FontChar(4, 5, 1, 630201); // N
    Chars[79] = new FontChar(4, 5, 1, 432534); // O
    Chars[80] = new FontChar(4, 5, 1, 96663); // P
    Chars[81] = new FontChar(4, 6, 1, 8821142); // Q
    Chars[82] = new FontChar(4, 5, 1, 620951); // R
    Chars[83] = new FontChar(4, 5, 1, 493086); // S
    Chars[84] = new FontChar(3, 5, 1, 9367); // T
    Chars[85] = new FontChar(4, 5, 1, 432537); // U
    Chars[86] = new FontChar(4, 5, 1, 152985); // V
    Chars[87] = new FontChar(5, 5, 1, 11196081); // W
    Chars[88] = new FontChar(4, 5, 1, 628377); // X
    Chars[89] = new FontChar(4, 5, 1, 429721); // Y
    Chars[90] = new FontChar(3, 5, 1, 29351); // Z

    // Unsupported chars: 91-96
    for (int i=91; i<=96; ++i)
        Chars[i] = UnsupportedChar;

    Chars[97] = new FontChar(4, 4, 2, 59806); // a
    Chars[98] = new FontChar(4, 5, 1, 498033); // b
    Chars[99] = new FontChar(3, 4, 2, 3150); // c
    Chars[100] = new FontChar(4, 5, 1, 956904); // d
    Chars[101] = new FontChar(4, 4, 2, 25558); // e
    Chars[102] = new FontChar(3, 5, 1, 9684); // f
    Chars[103] = new FontChar(4, 6, 2, 6875550); // g
    Chars[104] = new FontChar(4, 5, 1, 629105); // h
    Chars[105] = new FontChar(1, 5, 1, 29); // i
    Chars[106] = new FontChar(2, 7, 1, 6818); // j
    Chars[107] = new FontChar(4, 5, 1, 619921); // k
    Chars[108] = new FontChar(1, 5, 1, 31); // l
    Chars[109] = new FontChar(5, 4, 2, 710319); // m
    Chars[110] = new FontChar(4, 4, 2, 39319); // n
    Chars[111] = new FontChar(4, 4, 2, 27030); // o
    Chars[112] = new FontChar(4, 6, 2, 1145239); // p
    Chars[113] = new FontChar(4, 6, 2, 8972702); // q
    Chars[114] = new FontChar(3, 4, 2, 605); // r
    Chars[115] = new FontChar(4, 4, 2, 31806); // s
    Chars[116] = new FontChar(3, 5, 1, 17594); // t
    Chars[117] = new FontChar(4, 4, 2, 59801); // u
    Chars[118] = new FontChar(4, 4, 2, 9625); // v
    Chars[119] = new FontChar(5, 4, 2, 338613); // w
    Chars[120] = new FontChar(3, 4, 2, 2709); // x
    Chars[121] = new FontChar(4, 6, 2, 6875545); // y
    Chars[122] = new FontChar(4, 4, 2, 62031); // z

    // Unsupported chars: 123-254
    for (int i=123; i<=254; ++i) Chars[i] = UnsupportedChar;
}

void Font::MeasureString(const String& str, int& width, int& height, int spacing)
{
	width = 0;
	height = 0;

	for (int i=0; i<str.length(); ++i)
	{
		char c = str[i];
		FontChar* fontChar = Chars[(int)c];

		width += fontChar->Width + spacing;
		if (fontChar->Height > height)
			height = fontChar->Height;
	}
}