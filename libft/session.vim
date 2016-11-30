let SessionLoad = 1
if &cp | set nocp | endif
nnoremap  o
vnoremap ,[ c[]P
vnoremap ,( c()P
vnoremap ," c""P
vnoremap ,' c''P
nnoremap ,( viwbi(ea)
nnoremap ,[ viwbi[ea]
nnoremap ," viwbi"ea"
nnoremap ,' viwbi'ea'
nnoremap ,hl :nohlsearch
nnoremap , O
nnoremap ,sv :source $MYVIMRC:nohlsearch
nnoremap ,aw :wall
nnoremap ,w :write
nnoremap - ddp
nnoremap H ^
nnoremap L $
nnoremap _ ddkkp
let s:cpo_save=&cpo
set cpo&vim
nmap gx <Plug>NetrwBrowseX
onoremap in{ :execute "normal! /{\r"<Left>vi{:nohlsearchi<Right>
onoremap in} :execute "normal! ?}\r"<Left>vi{:nohlsearchi<Right>
onoremap in( :execute "normal! /(\r"<Left>vi(:nohlsearchi<Right>
onoremap in) :execute "normal! ?)\r:nohlsearch\r"<Left>vi(
vnoremap ii 
nnoremap j gj
nnoremap k gk
nmap <F1> :Stdheader
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
nnoremap <BS>sw :!rm ~/.vim/swap/*
noremap <Left> <Nop>
noremap <Right> <Nop>
noremap <Down> <Nop>
noremap <Up> <Nop>
nnoremap <F2> :call Insert_header_42()
inoremap  viwUi
inoremap  <Nop>
inoremap ,o jA
inoremap ,w :write
inoremap ii 
iabbr mg Max Gautier
iabbr @@ mgautier@student.42.fr
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set background=dark
set backspace=indent,eol,start
set backup
set backupdir=~/.vim/backup//
set directory=~/.vim/swap//
set fileencodings=ucs-bom,utf-8,default,latin1
set foldlevelstart=10
set helplang=en
set hidden
set hlsearch
set ignorecase
set incsearch
set laststatus=2
set modelines=1
set mouse=a
set scrolloff=100
set shiftwidth=4
set showcmd
set showmatch
set smartcase
set smartindent
set softtabstop=4
set statusline=%f\ %y\ %m\ %{strftime('%c')}%=Line\ %l\ of\ %L\ /\ Column\ %c
set tabstop=4
set title
set undodir=~/.vim/undo//
set wildmenu
set window=0
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/Travail/libft/libft
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +39 libft-norme-test.h
badd +13 ft_strlen.c
badd +23 ft_strlcat.c
badd +15 ft_strcat.c
badd +19 ft_strcmp.c
badd +19 ft_strcpy.c
badd +16 ft_strdup.c
badd +18 ft_strncat.c
badd +16 ft_strncmp.c
badd +20 ft_strncpy.c
badd +29 Makefile
badd +22 test/main.c
badd +146 test/tests.c
badd +40 test/tests.h
badd +18 tests.h
badd +1 ft_memalloc.o
badd +17 ft_memalloc.c
badd +18 ft_memdel.c
badd +18 ft_strnew.c
badd +18 ft_strdel.c
badd +16 ft_strclr.c
badd +15 ft_striter.c
badd +17 ft_striteri.c
badd +15 ft_strmap.c
badd +17 ft_strmapi.c
badd +16 ft_strequ.c
badd +18 ft_strnequ.c
badd +27 ft_strsub.c
badd +16 ft_strjoin.c
badd +60 ft_strtrim.c
badd +69 ft_strsplit.c
badd +21 ft_itoa.c
badd +1 /g
badd +1 ft_putchar_fd.c
badd +1 ft_putstr.c
badd +1 ft_putendl_fd.c
badd +15 ft_putnbr.c
badd +13 ft_iota.c
badd +1 ft_putendl.c
badd +30 ft_putnbr_fd.c
badd +14 ft_putchar.c
badd +1 ft_putstr_fd.c
badd +16 ft_memset.c
badd +16 ft_bzero.c
badd +17 ft_memcpy.c
badd +19 ft_memccpy.c
badd +17 ft_memmove.c
badd +18 ft_memchr.c
badd +18 ft_memcmp.c
badd +32 ft_strrchr.c
badd +31 ft_strchr.c
badd +48 ft_strnstr.c
badd +26 ft_strstr.c
badd +16 ft_atoi.c
badd +1 ft_isalpha.c
badd +1 ft_isdigit.c
badd +1 ft_isalnum.c
badd +1 ft_isascii.c
badd +13 ft_print.c
badd +1 ft_isprint.c
badd +1 ft_toupper.c
badd +15 ft_tolower.c
badd +1 ft_isprint
badd +41 ft_lstnew.c
badd +18 ft_lstdelone.c
badd +22 ft_lstdel.c
badd +15 ft_lstadd.c
badd +21 ft_lstiter.c
badd +19 ft_lstmap.c
badd +22 test/list_test.c
badd +1 libft.h
badd +2 temp
badd +17 ft_itoa_base.c
args /g
edit ft_strncpy.c
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd w
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 89 + 135) / 270)
exe 'vert 2resize ' . ((&columns * 90 + 135) / 270)
exe 'vert 3resize ' . ((&columns * 89 + 135) / 270)
argglobal
setlocal autoindent
setlocal nobinary
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal cindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=80
setlocal comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:*,ex:*/,://
setlocal commentstring=/*%s*/
setlocal complete=.,w,b,u,t,i
setlocal completefunc=
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
set cursorline
setlocal cursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal noexpandtab
if &filetype != 'c'
setlocal filetype=c
endif
setlocal foldcolumn=0
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=10
setlocal foldmarker={{{,}}}
set foldmethod=syntax
setlocal foldmethod=syntax
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=0
setlocal include=
setlocal includeexpr=
setlocal indentexpr=
setlocal indentkeys=0{,0},:,0#,!^F,o,O,e
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
setlocal nolinebreak
setlocal nolisp
setlocal nolist
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal modeline
setlocal modifiable
setlocal nrformats=octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=ccomplete#Complete
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
setlocal norelativenumber
setlocal noscrollbind
setlocal shiftwidth=4
setlocal noshortname
setlocal smartindent
setlocal softtabstop=4
setlocal nospell
setlocal spellcapcheck=
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=
setlocal suffixesadd=
setlocal swapfile
setlocal synmaxcol=3000
if &syntax != 'c'
setlocal syntax=c
endif
setlocal tabstop=4
setlocal tags=
setlocal textwidth=0
setlocal thesaurus=
setlocal noundofile
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
15
normal zo
let s:l = 16 - ((15 * winheight(0) + 39) / 79)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
16
normal! 0
wincmd w
argglobal
edit test/main.c
setlocal autoindent
setlocal nobinary
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal cindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=80
setlocal comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:*,ex:*/,://
setlocal commentstring=/*%s*/
setlocal complete=.,w,b,u,t,i
setlocal completefunc=
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
set cursorline
setlocal cursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal noexpandtab
if &filetype != 'c'
setlocal filetype=c
endif
setlocal foldcolumn=0
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=10
setlocal foldmarker={{{,}}}
set foldmethod=syntax
setlocal foldmethod=syntax
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=0
setlocal include=
setlocal includeexpr=
setlocal indentexpr=
setlocal indentkeys=0{,0},:,0#,!^F,o,O,e
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
setlocal nolinebreak
setlocal nolisp
setlocal nolist
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal modeline
setlocal modifiable
setlocal nrformats=octal,hex
set number
setlocal nonumber
setlocal numberwidth=4
setlocal omnifunc=ccomplete#Complete
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
set relativenumber
setlocal norelativenumber
setlocal noscrollbind
setlocal shiftwidth=4
setlocal noshortname
setlocal smartindent
setlocal softtabstop=4
setlocal nospell
setlocal spellcapcheck=
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=
setlocal suffixesadd=
setlocal swapfile
setlocal synmaxcol=3000
if &syntax != 'c'
setlocal syntax=c
endif
setlocal tabstop=4
setlocal tags=
setlocal textwidth=0
setlocal thesaurus=
setlocal noundofile
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
17
normal zo
85
normal zo
17
normal zo
let s:l = 22 - ((21 * winheight(0) + 39) / 79)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
22
normal! 01l
wincmd w
argglobal
edit libft.h
setlocal autoindent
setlocal nobinary
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal cindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=80
setlocal comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:*,ex:*/,://
setlocal commentstring=/*%s*/
setlocal complete=.,w,b,u,t,i
setlocal completefunc=
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
set cursorline
setlocal cursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal noexpandtab
if &filetype != 'cpp'
setlocal filetype=cpp
endif
setlocal foldcolumn=0
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=10
setlocal foldmarker={{{,}}}
set foldmethod=syntax
setlocal foldmethod=syntax
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=0
setlocal include=
setlocal includeexpr=
setlocal indentexpr=
setlocal indentkeys=0{,0},:,0#,!^F,o,O,e
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
setlocal nolinebreak
setlocal nolisp
setlocal nolist
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal modeline
setlocal modifiable
setlocal nrformats=octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=ccomplete#Complete
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
setlocal norelativenumber
setlocal noscrollbind
setlocal shiftwidth=4
setlocal noshortname
setlocal smartindent
setlocal softtabstop=4
setlocal nospell
setlocal spellcapcheck=
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=
setlocal suffixesadd=
setlocal swapfile
setlocal synmaxcol=3000
if &syntax != 'cpp'
setlocal syntax=cpp
endif
setlocal tabstop=4
setlocal tags=
setlocal textwidth=0
setlocal thesaurus=
setlocal noundofile
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
let s:l = 56 - ((39 * winheight(0) + 39) / 79)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
56
normal! 07l
wincmd w
exe 'vert 1resize ' . ((&columns * 89 + 135) / 270)
exe 'vert 2resize ' . ((&columns * 90 + 135) / 270)
exe 'vert 3resize ' . ((&columns * 89 + 135) / 270)
tabnext 1
if exists('s:wipebuf')
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToO
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
