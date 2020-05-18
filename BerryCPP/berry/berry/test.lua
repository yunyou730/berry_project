local function test1()
	print("This is test1")
end

local function test2()
	print("1111")
	local test = create_berry_object(3,"aaa")
	print("[test] " .. tostring(test))

	delete_berry_object(test);
	print("[test] " .. tostring(test))
end

local function test3()

	print("--------")
	local r1,r2,r3,r4,r5 = test_lua_call_cpp(1,"222",{["syz"] = "syz",[1] = "miao",[2] = "ayy",[3] = 417,[4] = 730});

	print(tostring(r1))
	print(tostring(r2))
	print(tostring(r3))
	print(tostring(r4))
	print(tostring(r5))
	--[[
	if type(ret) == "table" then
		for k,v in pairs(ret) do
			print("[k]" .. k)
			print("[v]" .. tostring(v))
		end
	end
	]]



	print("================")
end

local function test4()
	local obj = create_berry_object2()
end

test1()
--test2()

abc = "alpha"
tbl = {
	["name"] = "myl",
	["age"] = 23
}

test3();
test4()
