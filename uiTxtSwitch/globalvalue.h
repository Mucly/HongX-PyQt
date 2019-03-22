#ifndef GLOBALVALUE_H
#define GLOBALVALUE_H

#define PropertyINI         "./property.ini"

#define INI_ELE_SYS         "SYSTEM/"
#define INI_ELE_WND         "SE-WND/"
#define INI_ELE_NEW         "NEW_CLASS/"
#define INI_ELE_S2Q         "SE_Name2QT_Name/"

#define INI_KEY_VER         "ini_ver"
#define INI_KEY_PRO_ROOT    "pro_root"
#define INI_KEY_PRO_INI     "pro_ini"
#define INI_KEY_PRO_IMAGE   "pro_image"
#define INI_KEY_UI_FORM     "qtui_form"
#define INI_KEY_UI_TOOLBAR  "qtui_toolbar"
#define INI_KEY_TXT_FORM    "setxt_form"
#define INI_KEY_TXT_TOOLBAR "setxt_toolbar"

#define SEINI_KEY_FORM      "system/FormPath"
#define SEINI_KEY_TOOLBAR   "system/ToolBarPath"
#define SEINI_KEY_IMAGE     "system/BmpPath"

#define PRO_QRC_NAME        "res_pro.qrc"

// Muc 2019-03-22 直接<string, string>就好了啊，非要搞成<string, int>，存心刁难维护的人啊
enum PropType
{
    // 0        1      2       3
    tmBYTE, tmSHORT, tmINT, tmWORD,
    // 4        5       6        7
    tmDWORD, tmLONG, tmFLOAT, tmINT64,
    // 8         9       10      11
    tmDOUBLE, tmENUM, tmSTRUCT, tmSTR,
    // 12     13      14       15
    tmUSTR, tmCHAR, tmBOOL, tmCLASS,
    // 16             17          18
    tmPROCEDURE, tmFontStream, tmUnknown
};

#endif // GLOBALVALUE_H
