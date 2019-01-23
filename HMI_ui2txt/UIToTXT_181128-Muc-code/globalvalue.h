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

enum PropType
{
    tmBYTE, tmSHORT, tmINT, tmWORD, tmDWORD, tmLONG, tmFLOAT, tmINT64, tmDOUBLE,
    tmENUM, tmSTRUCT,
    tmSTR, tmUSTR, tmCHAR, tmBOOL,
    tmCLASS, tmPROCEDURE,
    tmFontStream,
    tmUnknown
};

#endif // GLOBALVALUE_H
