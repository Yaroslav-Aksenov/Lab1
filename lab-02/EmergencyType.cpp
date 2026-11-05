#include "EmergencyType.hpp"
#include <iostream>

namespace emergency
{
    EmergencyType::EmergencyType(int id, std::string_view name, std::string_view category, int dangerLevel)
        : m_id{ id }
        , m_name{ name }
        , m_category{ category }
        , m_dangerLevel{ dangerLevel }
    {
        std::cout << "[EmergencyType] Создан: " << m_name << "\n";
    }

    EmergencyType::EmergencyType()
        : m_id{ 0 }
        , m_name{ "Неизвестный" }
        , m_category{ "Неизвестно" }
        , m_dangerLevel{ 1 }
    {
        std::cout << "[EmergencyType] Создан пустой тип\n";
    }

    EmergencyType::~EmergencyType()
    {
        std::cout << "[EmergencyType] Уничтожен: " << m_name << "\n";
    }

    int EmergencyType::GetId() const { return m_id; }
    std::string_view EmergencyType::GetName() const { return m_name; }
    std::string_view EmergencyType::GetCategory() const { return m_category; }
    int EmergencyType::GetDangerLevel() const { return m_dangerLevel; }

    void EmergencyType::SetDangerLevel(int level)
    {
        // Правило: уровень опасности от 1 до 5
        if (level < 1 || level > 5)
        {
            std::cout << "[Ошибка] Уровень опасности должен быть от 1 до 5, получено: " << level << "\n";
            return;
        }
        m_dangerLevel = level;
    }

    bool EmergencyType::IsHighDanger() const
    {
        return m_dangerLevel >= 4;
    }
} // namespace emergency