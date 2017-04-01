#ifndef THINGS_H
#define THINGS_H

namespace uml {

// 可见性通过在属性或方法名称前增加特定的符号表示。公共的（+）私有的的（-）受保护的（#）包内的（~）
enum class AccessableType {
    Private = 0,
    Protected = 1,
    Public = 2,
    Package
};

enum class EndType {
    None = 0,
    Component,
};

/*
 *
依赖(dependency)是一种使用关系，他描述一个事物的规约变化可能影响到使用它的另一个事物。个人认为在参数或者方法体中使用到另外的类就是对该类有依赖的关系。use a

泛化(dependency)用于描述子类到父类之间的关系。 Is a kind of

关联(association)是一种结构关系，他描述一个对象与另一个对象相联系。 Has a
双向关联(association)通过A对象可以找到B对象，B对象同样可以找到A对象的关联为双向关联。

单向关联(direction-association)通过A对象可以找到B对象，但通过B对象不能找到A对象的关联为单向关联。

聚合(aggreation)A对象是B对象的一个组成部份，但A对象同时可能是C对象的组成部分这种关联为聚合。

组合(composition)A对象是B对象的一个组成部份，除非B对象将A对象转交给其他对象，否则A对象只能是B对象的组成部分，这种关联为组合。

 */
enum class LineType {
    NoneValue = 0,
    Generalization,
    Implementation,
    Dependence,
    Association,
    Aggregation,
    Composition,
    Included,
    Extended,
    Refined,
};

struct Entity {
    std::string name;
    std::string comment;
};

struct End: public Entity {

};

struct Line: public Entity {
    End source;
    End target;
};

struct Text: public Entity {
};

struct Note: public Entity {
};

struct Actor: public Entity {
};

struct UseCase: public Entity {
};

struct Subsystem: public Entity {
};

struct Interface: public Entity {
    struct Parameter {
        std::string name;
        std::string type;
        std::string defaultValue;
    };

    // 属性在类下面的第二栏中列出，可以仅显示操作名
    // 静态操作与静态属性同样通过在名称下加下划线表示
    // 抽象操作与抽象类同样通过斜体字表示
    // 操作特征完整语法: [可见性] 操作名 [([方向] 参数名 ':' 参数类型 ['=' 默认值])] [':' 返回类型] [{特征串}]
    // 不能重写的操作与属性一样使用特征串中增加 leaf 表示
    struct Operation {
        AccessableType accesable;
        bool isAbstract;
        bool isStatic;
        bool isLeaf;
        std::string returnType;
        std::string name;
        std::list<Parameter> parameters;
    };

    std::list<Operation> operations;
};

// 在UML中类以一个矩形表示，类的名称用一个字符串表示
// 抽象类通过将类名改为斜体字表
// 不能继承的类（叶子类，封闭类）通过在类名下面增加 leaf 特性说明。
struct Class: public Interface {

    // 属性在类下面的栏中列出，可以仅显示属性名
    // 属性其他特征完整语法: [可见性] 属性名 [':'类型] [多重性] ['='初始值] [{特性串]}]
    // 不能重写属性通过在特性串中增加 leaf 特性说明
    // 静态属性通过在属性名下加下划线表示
    struct Attribute : public Parameter {
        AccessableType accessable;
        bool isStatic;
        bool isLeaf;
    };

    bool isAbstract;
    bool isLeaf;

    std::list<Parameter> templateParameter;
    std::list<Attribute> attributes;
};

struct Package: public Entity {
};

/*
二、状态图元素（State Diagram Elements）
状态有Opened、Closed、Locked。

事件有 Open、Close、Lock和Unlock。

注意：

1、             并不是所有的事件都会引起状态的转移，比如当门是处于【Opened】状态，不能进行【Lock】事件。

2、             转移（Transition）有警备条件（guard condition），比如只有doorWay->isEmpty 条件满足时，才会响应事件。
*/


// 状态（States）
struct State: public Entity {
};

// 初态和终态（Initial and Final States）
// 初态用实心圆点表示，终态用圆形内嵌圆点表示。
struct InitialState: public Entity {
};

struct FinalState: public Entity {
};

// 转移（Transitions）
/*
 转移（Transitions）是两个状态之间的一种关系，表示对象将在源状态（Source State）中执行一定的动作，并在某个特定事件发生而且某个特定的警界条件满足时进入目标状态（Target State）



      事件标记（Trigger）：是转移的诱因，可以是一个信号，事件、条件变化（a change in some condition）和时间表达式。

      警界条件（Guard Condition）：当警界条件满足时，事件才会引发转移（Transition）。

      结果（Effect）：对象状态转移后的结果。
      */
struct Transition: public Entity {
};

// 动作（State Actions）
struct StateAction: public Entity {
};

// 自身转移（Self-Transitions）
struct SelfTransition: public Entity {
};

// 组合状态（Compound States）
struct CompoundState: public Entity {
};

// 进入节点（Entry Point）
struct EntryPoint: public Entity {
};

// 退出节点（Exit Point）
struct ExitPoint: public Entity {
};

// 历史状态（History States）
struct HistoryStates: public Entity {
};

// 并发区域（Concurrent Regions）
struct ConcurrentRegions: public Entity {
};

//
// 活动图中的各个元素
//

// 活动
struct Activity: public Entity {
};

// 动作
struct Action: public Entity {
};

// 动作约束
struct Conditions: public Entity {
};

// 控制流
struct ActivityEdge: public Entity {
};

// 初始节点
struct InitialNode: public Entity {
};

// 结束节点
struct FinalNode: public Entity {
};

// 对象
struct ObjectInActivity: public Entity {
};

// 对象流
struct ObjectFlow: public Entity {
};

// 数据存储
struct DataStore: public Entity {
};

// 判断节点
struct DecisionNode: public Entity {
};

// 合并节点
struct MergeNode: public Entity {
};

// 分叉节点
struct ForkNode: public Entity {
};

// 结合节点
struct JoinNode: public Entity {
};

// 扩展域
struct ExpansionRegion: public Entity {
};

// 异常处理器
struct ExceptionHandler: public Entity {
};

// 可中断活动区
struct InterruptibleActivityRegion: public Entity {
};

// 分割
struct Partitions: public Entity {
};

};

#endif // THINGS_H
