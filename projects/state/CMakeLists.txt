set(HDR TableView.h State.h Data.h AutoRefreshState.h NonAutoRefreshState.h)
set(SRC TableView.cc State.cc AutoRefreshState.cc NonAutoRefreshState.cc)
add_executable("state" "main.cc" ${HDR} ${SRC})
