" Synesis C/C++ project .vimrc — aligned with .sis/.vscode/c_cxx/settings.json

set nocompatible
filetype indent plugin on
syntax enable
set autoindent
set backspace=indent,eol,start
set hlsearch
set incsearch
set number

" files.insertFinalNewline
set eol
set fixeol

" editor.renderWhitespace: all
set list
set listchars=tab:->,trail:-,extends:>,precedes:<,nbsp:+

" editor.detectIndentation: false — global defaults (editor.tabSize: 4, insertSpaces: true)
set colorcolumn=76
set expandtab
set shiftwidth=4
set softtabstop=4
set tabstop=4

" colorcolumn draws a full-column tint in Vim (not a VS Code-style 1px line).
" Keep it subtle via the ColorColumn highlight group; reapply after colorscheme changes.
if has('termguicolors')
  " set termguicolors
endif

function! s:ConfigureColorColumn() abort
  highlight ColorColumn ctermbg=236 guibg=#2a2a2a cterm=NONE gui=NONE
endfunction

call s:ConfigureColorColumn()
autocmd ColorScheme * call s:ConfigureColorColumn()

" files.trimTrailingWhitespace
autocmd BufWritePre * %s/\s\+$//e

augroup sis_c_cxx
  autocmd!
  " [bat]
  autocmd FileType bat,dosbatch setlocal expandtab tabstop=4 shiftwidth=4 softtabstop=4 colorcolumn=60,76

  " [c] / [cpp]
  autocmd FileType c,cpp setlocal expandtab tabstop=4 shiftwidth=4 softtabstop=4 colorcolumn=60,64,68,72,76

  " [cmake]
  autocmd FileType cmake setlocal noexpandtab tabstop=4 shiftwidth=4 softtabstop=4

  " [json] / [markdown] / [ruby] / [yaml]
  autocmd FileType json,markdown,ruby,yaml setlocal expandtab tabstop=2 shiftwidth=2 softtabstop=2

  " [python]
  autocmd FileType python setlocal expandtab tabstop=4 shiftwidth=4 softtabstop=4 colorcolumn=60,76

  " [rust]
  autocmd FileType rs setlocal expandtab tabstop=4 shiftwidth=4 softtabstop=4 colorcolumn=76

  " [shellscript]
  autocmd FileType bash,sh,zsh setlocal expandtab tabstop=2 shiftwidth=2 softtabstop=2 colorcolumn=60,76

  " [toml]
  autocmd FileType toml setlocal noexpandtab tabstop=2 shiftwidth=2 softtabstop=2

augroup END

