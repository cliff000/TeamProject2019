-- requires
-- Lume（汎用ライブラリ）
Lume = require 'lume.lume'

-- class library（クラスベース用ライブラリ）
Class = require '30log.30log'

---------------------------------------
-- 初めに一度だけ呼ばれる関数
---------------------------------------
function love.load()
    -- 背景色の変更
    love.graphics.setBackgroundColor(0.95, 0.95, 0.95, 1)
end

function love.update(dt)
end

function love.draw()
end
