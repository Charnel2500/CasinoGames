cmake_minimum_required(VERSION 3.21.0)
project(CasinoGames VERSION 0.1.0 LANGUAGES CXX)

add_executable(CasinoGames 
    main.cpp
    dicePoker.cpp
    gameInfo.cpp
    hangman.cpp
    playerType.cpp
    tarot.cpp
    ticTacToe.cpp
)

add_custom_target(clean_target
    COMMAND rm -rf ${CMAKE_BINARY_DIR}/*.o ${CMAKE_BINARY_DIR}/CasinoGames
)

add_custom_target(pack
    COMMAND ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_BINARY_DIR}/CasinoGames_Source.zip"
            "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/dicePoker.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/gameInfo.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/hangman.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/playerType.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/tarot.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/ticTacToe.cpp"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Creating source archive"
)
