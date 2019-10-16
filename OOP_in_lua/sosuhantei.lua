-- すきゃんえふ
local input = 18
-- 双子の候補
local temp_1, temp_2 = input - 1, input + 1

local function hantei()
    -- ここはきこうね
    if input % 2 ~= 0 then
        return 'あうと'
    end

    -- 割れるとこまで
    for i = 2, (temp_2 + 1) / 2 - 1 do
        -- 割れたらアウト
        if temp_2 % i == 0 then
            return 'あうと'
        elseif temp_2 / 2 == i then
            return 'いえーい'
        end
    end

    return '?'
end

local a = hantei()

print(a)
