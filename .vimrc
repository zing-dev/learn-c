set nu

"语法高亮
syntax enable
syntax on 

"设置配色方案
colorscheme  desert  


"可以在buffer的任何地方使用鼠标  
set mouse=a  
set selection=exclusive  
set selectmode=mouse,key 

"高亮显示匹配的括号  
set showmatch 

"打开文件类型自动检测功能  
filetype on   


"设置taglist  
let Tlist_Show_One_File=0   "显示多个文件的tags  
let Tlist_File_Fold_Auto_Close=1 "非当前文件，函数列表折叠隐藏  
let Tlist_Exit_OnlyWindow=1 "在taglist是最后一个窗口时退出vim  
let Tlist_Use_SingleClick=1 "单击时跳转  
let Tlist_GainFocus_On_ToggleOpen=1 "打开taglist时获得输入焦点  
let Tlist_Process_File_Always=1 "不管taglist窗口是否打开，始终解析文件中的tag  




"设置缩进  
set tabstop=4  
set softtabstop=4  
set shiftwidth=4  
set autoindent  
set cindent  
if &term=="xterm"  
    set t_Co=8  
    set t_Sb=^[[4%dm  
    set t_Sf=^[[3%dm  
endif   
