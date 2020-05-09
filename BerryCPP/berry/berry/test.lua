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

test1()
--test2()

abc = "alpha"

tbl = {
	["name"] = "myl",
	["age"] = 23
}
