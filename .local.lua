local api = vim.api
local set = vim.opt


local keymap = api.nvim_set_keymap

keymap('n', '<F1>', ':!ninja -C build<CR>', {noremap = true})
