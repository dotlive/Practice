set(3rd_include_path
	"${3RD_PARTY_INC_DIR}/gtest/"
	"${3RD_PARTY_INC_DIR}/rapidxml/"
	"${3RD_PARTY_INC_DIR}/rapidjson/"
)

set(3rd_binary_path
	"${3RD_PARTY_BIN_DIR}/gtest"
	"${3RD_PARTY_BIN_DIR}/rapidxml"
	"${3RD_PARTY_BIN_DIR}/rapidjson"
)

set(3rd_binary_libs
	${LIB_PRE_NAME}gtest.${LIB_EXT_NAME}
	${LIB_PRE_NAME}gtest_main.${LIB_EXT_NAME}
	${LIB_PRE_NAME}rapidxml.${LIB_EXT_NAME}
	${LIB_PRE_NAME}rapidjson.${LIB_EXT_NAME}
)

function(link_3rd_party target)
	foreach(lib ${3rd_binary_libs})
		target_link_libraries(${target} ${lib})
	endforeach()
endfunction()