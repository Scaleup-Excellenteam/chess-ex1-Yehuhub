# target_sources (Chess PRIVATE "main.cpp"
# 							  "Chess.cpp"
# 							  "BoardManager.cpp"
# 							  "PieceFactory.cpp"
# 							  "Rook.cpp")

file(GLOB SOURCES "*.cpp")
target_sources(Chess PRIVATE ${SOURCES})