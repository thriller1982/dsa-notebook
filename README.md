# Data Structures and Algorithm Analysis - Learning Notebook

![Language](https://img.shields.io/badge/language-C-blue.svg)
![Standard](https://img.shields.io/badge/std-C11-blue)
![IDE](https://img.shields.io/badge/IDE-CLion-brightgreen)
![Status](https://img.shields.io/badge/Status-Learning-orange)

## 简介

这是一个用来记录数据结构与算法学习过程的仓库，主要使用 C 语言实现。
当前仓库已按“模块化 + 统一构建”方式整理，方便后续持续新增更多数据结构主题。

## 技术栈

- 语言：C (C11)
- 构建工具：CMake
- 开发环境：CLion / VS Code / 命令行
- 编译器：GCC / Clang / MSVC（取决于本机环境）

## 目录结构

```text
DSA-Notebook/
├── CMakeLists.txt          # 根构建入口，统一管理所有子模块
├── README.md
├── .gitignore
├── common/                 # 公共代码（当前为 fatal 错误处理）
│   ├── CMakeLists.txt
│   ├── fatal.c
│   └── fatal.h
├── binary_heap/            # 二叉堆实现
│   ├── CMakeLists.txt
│   ├── binary_heap.c
│   └── binary_heap.h
├── hash_table/             # 分离链接哈希表实现
│   ├── CMakeLists.txt
│   ├── sc_hash_table.c
│   ├── sc_hash_table.h
│   └── sc_hash_table.md
├── examples/               # 示例入口（预留）
│   └── CMakeLists.txt
└── tests/                  # 测试目录（预留）
    └── CMakeLists.txt
```

## 构建说明

在项目根目录执行：

```bash
cmake -S . -B build
cmake --build build
```

说明：
- `BUILD_EXAMPLES` 默认 `ON`（当前目录为预留占位，后续可添加 demo）。
- `BUILD_TESTS` 默认 `OFF`（后续补测试时开启）。

示例：

```bash
cmake -S . -B build -DBUILD_TESTS=ON
cmake --build build
```

## 当前模块

- `binary_heap`：二叉堆（优先队列）基础实现
- `hash_table`：分离链接法哈希表实现

## 后续计划

- 在 `examples/` 添加可运行 `main` 示例
- 在 `tests/` 增加基础单元测试
- 持续补充更多数据结构模块（如 AVL、排序、图等）
